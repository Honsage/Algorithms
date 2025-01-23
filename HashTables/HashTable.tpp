#ifndef HASHTABLE_TPP
#define HASHTABLE_TPP
#include <iostream>
#include <stdlib.h>


template<typename K, typename V>
HashTable<K, V>* HashTable<K, V>::create(HashMapType type, const unsigned int& capacity) {
    switch (type) {
        case HashMapType::OpenAddressing: {
            return new OpenHashTable<K, V>(capacity);
        }
        case HashMapType::SeparateChaining: {
            return new ChainHashTable<K, V>(capacity);
        }
        default: {
            return nullptr;
        }
    }
}

template<typename K, typename V>
unsigned int HashTable<K, V>::size() const {
    return this->m_size;
}

template<typename K, typename V>
bool HashTable<K, V>::empty() const {
    return this->m_size == 0;
}

template<typename K, typename V>
HashTable<K, V>::HashTable(): m_capacity(0), m_size(0) {}

template<typename K, typename V>
OpenHashTable<K, V>::OpenHashTable(unsigned int capacity) : HashTable<K, V>(), EXPAND_SIZE(10) {
    if (capacity < this->EXPAND_SIZE) {
        capacity = this->EXPAND_SIZE;
    }
    this->m_capacity = capacity;
    this->m_data = new Entry *[this->m_capacity];
    for (int i = 0; i < this->m_capacity; ++i) {
        this->m_data[i] = nullptr;
    }
    this->m_marked_entry = new Entry(0, 0);
}

template<typename K, typename V>
OpenHashTable<K, V>::~OpenHashTable() {
    for (int i = 0; i < this->m_capacity; ++i) {
        delete this->m_data[i];
    }
    delete[] this->m_data;
}

template<typename K, typename V>
V OpenHashTable<K, V>::get(const K &key) const {
    if (! this->contains(key)) {
        std::cerr << "There is no entry with this key in Hash Table!";
        return this->m_marked_entry->value;
    }
    int t = 0;
    unsigned int hash_code;
    do {
        hash_code = this->hashOf(key, t);
        ++t;
        // if(t == this->m_capacity) {
        //     std::cerr << "Cannot find this key!\n";
        //     return this->m_marked_entry->value;
        // }
    } while(this->m_data[hash_code]->key != key);

    return this->m_data[hash_code]->value;
}

template<typename K, typename V>
bool OpenHashTable<K, V>::contains(const K &key) const {
    return false;
}

template<typename K, typename V>
void OpenHashTable<K, V>::set(const K &key, const V &value) {
    int t = 0;
    unsigned int hash_code;
    do {
        hash_code = this->hashOf(key, t);
        ++t;
    } while(this->m_data[hash_code] != nullptr);

    this->m_data[hash_code] = new Entry(key, value);
    ++this->m_size;

    if (this->m_size > 0.75 * this->m_capacity) {
        this->resize(this->m_capacity + this->EXPAND_SIZE);
    }
}

template<typename K, typename V>
void OpenHashTable<K, V>::remove(const K &key) {
}

template<typename K, typename V>
void OpenHashTable<K, V>::clear() {
}

template<typename K, typename V>
unsigned int OpenHashTable<K, V>::hashOf(const K& key, const int i) const {
    int _key = static_cast<int>(key);
    const int h1 = _key % this->m_capacity;
    const int h2 = _key % (this->m_capacity - 1) + 1;
    return (h1 + i * h2) % this->m_capacity;
}

template<typename K, typename V>
void OpenHashTable<K, V>::resize(unsigned int new_capacity) {
}


#endif //HASHTABLE_TPP
