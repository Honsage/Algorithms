#ifndef HASHTABLE_H
#define HASHTABLE_H

template <typename K, typename V>
class HashTable {
private:
    struct Entry {
        K key;
        V value;
        Entry(K key, V value) : key(key), value(value) {}
    };
    unsigned int size;
    Entry* data;
public:
    explicit HashTable(unsigned int size = 10);
};

#include "HashTable.tpp"

#endif //HASHTABLE_H
