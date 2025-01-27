#include <queue>

#include "huffman.h"

#include <iostream>

HuffmanCompressor::HuffmanCompressor() {}

void HuffmanCompressor::encode(const std::string& text) {
    this->reset();

    std::unordered_map<char, int> frequency_table;
    for (char c : text) {
        ++frequency_table[c];
    }

    std::priority_queue<Node*, std::vector<Node*>, comp> p_queue;

    for (auto record : frequency_table) {
        p_queue.push(new Node(record.first, record.second, nullptr, nullptr));
    }

    Node* left;
    Node* right;
    while (p_queue.size() != 1) {
        left = p_queue.top();
        p_queue.pop();
        right = p_queue.top();
        p_queue.pop();

        unsigned int common_freq = left->freq + right->freq;
        p_queue.push(new Node('\0', common_freq, left, right));
    }

    this->root = p_queue.top();
    this->recursive_encoding(this->root);
    // huffman codes are computed

    for (char c : text) {
        this->m_compressed_text += this->m_huffman_codes[c];
    }
}

std::string HuffmanCompressor::decode() {
    int index = -1;
    const int encoded_size = static_cast<int>(this->m_compressed_text.size());
    while (encoded_size != 0 && index < encoded_size) {
        this->recursive_decoding(this->root, index);
    }
    return "";
}

std::unordered_map<char, std::string> HuffmanCompressor::get_huffman_codes() {
    return this->m_huffman_codes;
}

std::string HuffmanCompressor::get_compressed_text() {
    return this->m_compressed_text;
}

void HuffmanCompressor::reset() {
    this->m_huffman_codes.clear();
    this->m_compressed_text = "";
    this->root = nullptr;
}

void HuffmanCompressor::recursive_encoding(Node* root, std::string code) {
    if (root == nullptr) {
        return;
    }
    if (! root->left && ! root->right) {
        this->m_huffman_codes[root->c] = code;
    }
    this->recursive_encoding(root->left, code + "0");
    this->recursive_encoding(root->right, code + "1");
}

void HuffmanCompressor::recursive_decoding(Node *root, int &index) {
    if (root == nullptr) {
        return;
    }
    if (! root->left && ! root->right) {
        std::cout << root->c;
        return;
    }
    index++;
    if (this->m_compressed_text[index] == '0') {
        this->recursive_decoding(root->left, index);
    } else {
        this->recursive_decoding(root->right, index);
    }
}
