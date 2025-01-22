#ifndef HASHTABLE_H
#define HASHTABLE_H

template <typename K, typename V>
class HashMap {
protected:
    HashMap();
public:
    static HashMap create();
};

template <typename K, typename V>
class OpenHashTable : HashMap<K, V> { // Open addressing

};

template <typename K, typename V>
class ChainHashTable { // Separate chaining / closed addressing

};

#include "HashTable.tpp"

#endif //HASHTABLE_H
