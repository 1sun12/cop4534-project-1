#ifndef H_HASHTABLE
#define H_HASHTABLE

#include <iostream>
#include "User.hpp"
#include "LinkedList.hpp"
#include "Cipher.hpp"

class HashTable {
    public:
        HashTable();
        ~HashTable();
        int insert(User); // argument is user object
        int insert(std::string, std::string); // argument is username and password; user ingredients
        User search(std::string); // find and return a user in the table
        void remove(std::string); // remove user from table given their username
        void printAt(int);
        void print();
    private:
        Cipher cipher;
        int const MIN_ASCII_VAL = 97;
        LinkedList* table; // array -> linked lists / buckets -> Users
        int const TABLE_SIZE = 88801;
        int hash(std::string);
        User searchHelper(Node*, std::string);
};

#endif