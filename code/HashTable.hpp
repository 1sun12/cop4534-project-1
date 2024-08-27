#ifndef H_HASHTABLE
#define H_HASHTABLE

#include <iostream>
#include "User.hpp"
#include "LinkedList.hpp"

class HashTable {
    public:
        HashTable();
        ~HashTable();
        int insert(User); // argument is user object
        int insert(std::string, std::string); // argument is username and password; user ingredients
        void remove(std::string); // remove user from table given their username
        User search(); // find and return a user in the table
        void printAt(int);
        void print();
    private:
        int const MIN_ASCII_VAL = 97;
        LinkedList* table; // array -> linked lists / buckets -> Users
        int const TABLE_SIZE = 88801;
};

#endif