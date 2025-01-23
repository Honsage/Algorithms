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
    unsigned int hash_idx;
    do {
        hash_idx = this->hashOf(key, t);
        ++t;
    } while(this->m_data[hash_idx]->key != key);

    return this->m_data[hash_idx]->value;
}

template<typename K, typename V>
bool OpenHashTable<K, V>::contains(const K &key) const {
    unsigned int hash_idx;
    for (int t = 0; t < this->m_capacity; ++t) {
        hash_idx = this->hashOf(key, t);
        if (this->m_data[hash_idx] == nullptr) return false;
        if (this->m_data[hash_idx] == this->m_marked_entry) continue;
        if (this->m_data[hash_idx]->key == key) return true;
    }
    return false;
}

template<typename K, typename V>
void OpenHashTable<K, V>::set(const K &key, const V &value) {
    if (! this->contains(key)) {
        ++this->m_size;
    }

    int t = 0;
    unsigned int hash_idx;
    do {
        hash_idx = this->hashOf(key, t);
        ++t;
    } while(this->m_data[hash_idx] != nullptr &&
            this->m_data[hash_idx] != this->m_marked_entry &&
            this->m_data[hash_idx]->key != key);

    this->m_data[hash_idx] = new Entry(key, value);

    if (this->m_size > 0.75 * this->m_capacity) {
        this->resize(this->m_capacity + this->EXPAND_SIZE);
    }
}

template<typename K, typename V>
void OpenHashTable<K, V>::remove(const K &key) {
    if (this->contains(key)) {
        int t = 0;
        unsigned int hash_idx;
        do {
            hash_idx = this->hashOf(key, t);
            ++t;
        } while(this->m_data[hash_idx]->key != key);
        this->m_data[hash_idx] = this->m_marked_entry;
    }
}

template<typename K, typename V>
void OpenHashTable<K, V>::clear() {
    for (int i = 0; i < this->m_capacity; ++i) {
        this->m_data[i] = nullptr;
    }
    this->m_size = 0;
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
    auto** obsolete_data = this->m_data;
    const unsigned int obsolete_capacity = this->m_capacity;

    this->m_data = new Entry* [new_capacity];
    this->m_capacity = new_capacity;
    this->m_size = 0;
    for (int i = 0; i < this->m_capacity; ++i) {
        this->m_data[i] = nullptr;
    }

    for (int i = 0; i < obsolete_capacity; ++i) {
        if (obsolete_data[i] != nullptr) {
            this->set(obsolete_data[i]->key, obsolete_data[i]->value);
        }
    }

    for (int i = 0; i < obsolete_capacity; ++i) {
        delete obsolete_data[i];
    }
    delete[] obsolete_data;
}


#endif //HASHTABLE_TPP
