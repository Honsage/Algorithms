#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <string>
#include <unordered_map>

class HuffmanCompressor {
public:
    HuffmanCompressor();

    void encode(const std::string& text);
    std::string decode();

    void reset();
private:
    struct Node {
        char c;
        unsigned int freq;
        Node* left;
        Node* right;
        Node(char c, unsigned int freq, Node* left, Node* right) :
            c(c), freq(freq), left(left), right(right) {}
    };

    struct comp {
        bool operator()(const Node* l, const Node* r) const {
            return l->freq > r->freq;
        }
    };

    std::unordered_map<char, std::string> m_huffman_codes;

    std::string m_compressed_text;
    Node* root;

    void recursive_encoding(Node* root, std::string code = "");
    void recursive_decoding(Node* root, int& index);
};



#endif //HUFFMAN_H
