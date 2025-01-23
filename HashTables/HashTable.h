#ifndef HASHTABLE_H
#define HASHTABLE_H

template <typename K, typename V>
class HashTable { // api for hash table functionality / abstract class
public:
    enum class HashMapType {
        OpenAddressing,
        SeparateChaining
    };

    static HashTable* create(HashMapType type = HashMapType::OpenAddressing, const unsigned int& capacity = 10); // fabric pattern

    virtual ~HashTable() = default;

    unsigned int size();
    bool empty();

    virtual V get(const K& key) const = 0;
    virtual bool contains(const K& key) const = 0;
    virtual void set(const K& key, const V& value) = 0;
    virtual void remove(const K& key) = 0;
    virtual void clear() = 0;

    // TODO: operator[]
protected:
    unsigned int m_capacity; // amount of cells available
    unsigned int m_size; // real amount of entries

    HashTable();

    virtual void resize() = 0;
};


template <typename K, typename V>
class OpenHashTable : HashTable<K, V> { // Open addressing
public:
    explicit OpenHashTable(unsigned int capacity = 10);
    ~OpenHashTable() override;

    V get(const K& key) const override;
    bool contains(const K& key) const override;
    void set(const K& key, const V& value) override;
    void remove(const K& key) override;
    void clear() override;
private:
    struct Entry {
        K key;
        V value;
        Entry(K key, V value) :
            key(key),
            value(value) {}
    };

    Entry* m_data;

    void resize() override;
};

template <typename K, typename V>
class ChainHashTable : HashTable<K, V> { // Separate chaining / closed addressing
public:
    explicit ChainHashTable(unsigned int capacity = 10);
    ~ChainHashTable() override;

    V get(const K& key) const override;
    bool contains(const K& key) const override;
    void set(const K& key, const V& value) override;
    void remove(const K& key) override;
    void clear() override;
private:
    struct Entry {
        K key;
        V value;
        Entry* next;
        Entry(K key, V value, Entry* next = nullptr) :
            key(key),
            value(value),
            next(next) {}
    };

    Entry* m_data;

    void resize() override;
};

#include "HashTable.tpp"

#endif //HASHTABLE_H
