#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream> // @TEMP

enum class HashMapType {
    OpenAddressing,
    SeparateChaining
};

template <typename K, typename V>
class HashTable { // api for hash table functionality / abstract class
public:
    static HashTable* create(HashMapType type = HashMapType::OpenAddressing, const unsigned int& capacity = 10); // fabric pattern

    virtual ~HashTable() = default;

    unsigned int size() const;
    bool empty() const;

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

    virtual void resize(unsigned int new_capacity) = 0;
};


template <typename K, typename V>
class OpenHashTable final : public HashTable<K, V> { // Open addressing
public:
    explicit OpenHashTable(unsigned int capacity = 10);
    ~OpenHashTable() override;

    V get(const K& key) const override;
    bool contains(const K& key) const override;
    void set(const K& key, const V& value) override;
    void remove(const K& key) override;
    void clear() override;

    // @TEMP
    void print() {
        for (int i = 0; i < this->m_capacity; ++i) {
            auto now = this->m_data[i];
            std::cout << i << " ";
            if (now == nullptr) {
                std::cout << "nullptr";
            } else if (now == this->m_marked_entry) {
                std::cout << "deleted (marked)";
            } else {
                std::cout << "key: " << now->key << " value: " << now->value;
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }

private:
    const unsigned int EXPAND_SIZE;

    struct Entry {
        K key;
        V value;
        Entry(K key, V value) :
            key(key),
            value(value) {}
    };

    Entry** m_data;
    Entry* m_marked_entry;

    unsigned int hashOf(const K& key, int i = 0) const;

    void resize(unsigned int new_capacity) override;
};


template <typename K, typename V>
class ChainHashTable : public HashTable<K, V> { // Separate chaining / closed addressing
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

    void resize(unsigned int new_capacity) override;
};


#include "HashTable.tpp"

#endif //HASHTABLE_H
