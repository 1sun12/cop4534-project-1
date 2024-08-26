#ifndef H_HASHTABLE
#define H_HASHTABLE

#include <iostream>

class HashTable {
    public:
        HashTable();
        ~HashTable();
    private:
        std::string* table;
        int const TABLE_SIZE = 100;
};

#endif