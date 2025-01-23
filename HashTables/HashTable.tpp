#ifndef HASHTABLE_TPP
#define HASHTABLE_TPP

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

#endif //HASHTABLE_TPP
