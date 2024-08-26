#include "HashTable.hpp"

HashTable::HashTable() {
    table = new std::string[TABLE_SIZE];
}

HashTable::~HashTable() {
    delete[] table;
}