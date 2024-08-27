#include "HashTable.hpp"

HashTable::HashTable() {
    table = new LinkedList[TABLE_SIZE]();
}

HashTable::~HashTable() {
    delete[] table;
}

void HashTable::insert(User user) {
    int nameSum = 0;
    int pwSum = 0;
    int uniqueR = 0;
    int placeInTable = 0;

    // 1.) convert name and password to unique integer representation
    // accomplished by converting each character to ascii and adding up their values
    
    // convert name
    for (long unsigned int i = 0; i < user.getName().length(); i++) {
        int asciiVal = (int)user.getName()[i] - MIN_ASCII_VAL;
        nameSum += asciiVal;
    }

    // convert pw
    for (long unsigned int i = 0; i < user.getPw().length(); i++) {
        int asciiVal = (int)user.getPw()[i] - MIN_ASCII_VAL;
        pwSum += asciiVal;
    }

    // sum unique representations; name + pw
    uniqueR = nameSum + pwSum;

    // 2.) modulos unique integer
    placeInTable = uniqueR % TABLE_SIZE;

    // 3.) insert into table at unique spot, at tail of it's respective bucket / linked-list
    table[placeInTable].insert(user);
}