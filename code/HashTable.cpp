#include "HashTable.hpp"

HashTable::HashTable() {
    table = new LinkedList[TABLE_SIZE]();
}

HashTable::~HashTable() {
    delete[] table;
}

int HashTable::insert(User user) {
    int placeInTable = hash(user.getName());

    std::cout << "Name b4 Insert: " << user.getName() << std::endl;

    // scramble / encrypt the data before inserting
    std::string encryptedPass = cipher.scramble(user.getPw());

    std::cout << "Enc. Pw b4 Insert: " << encryptedPass << std::endl;

    // insert into table at unique hash
    User temp(user.getName(), encryptedPass);
    table[placeInTable].insert(temp);

    std::cout << "Place In T: " << placeInTable << std::endl;

    return placeInTable;
}

int HashTable::insert(std::string name, std::string pass) {
    int placeInTable = hash(name);

    // scramble / encrypt the data before inserting
    std::string encryptedPass = cipher.scramble(pass);

    // insert into table at unique hash
    User temp(name, encryptedPass);
    table[placeInTable].insert(temp);

    return placeInTable;
}

int HashTable::hash(std::string wordToHash) {
    int sum = 0;
    for (long unsigned int i = 0; i < wordToHash.length(); i++) {
        int asciiVal = (int)wordToHash[i] - MIN_ASCII_VAL;
        sum += asciiVal;
    }

    // scramble the name and add; makes hashing more complex and spread even in table
    std::string wordEnc = cipher.scramble(wordToHash);
    for (long unsigned int i = 0; i < wordEnc.length(); i++) {
        int asciiVal = (int)wordEnc[i] - MIN_ASCII_VAL;
        sum += asciiVal;
    }

    return sum % TABLE_SIZE;
}

void HashTable::printAt(int index) {
    table[index].printList();
}

void HashTable::print() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i].getHead() != nullptr) {
            std::cout << "Item Index: " << i << std::endl;
            table[i].printList();
        }
    }
}