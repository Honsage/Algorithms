#ifndef HASHTABLE_TPP
#define HASHTABLE_TPP

template<typename K, typename V>
HashTable<K, V>::HashTable(unsigned int size) {
    this->size = size;
    this->data = new Entry[this->size];
}






#endif //HASHTABLE_TPP