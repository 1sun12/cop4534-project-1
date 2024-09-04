#include "HashTable.hpp"

HashTable::HashTable() {
    table = new LinkedList[TABLE_SIZE]();
}

HashTable::~HashTable() {
    delete[] table;
}

int HashTable::insert(User user) {
    int placeInTable = hash(user.getName());

    // scramble / encrypt the data before inserting
    std::string encryptedPass = cipher.scramble(user.getPw());

    // insert into table at unique spot, at tail of it's respective bucket / linked-list
    User temp(user.getName(), encryptedPass);
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

int HashTable::insert(std::string name, std::string pass) {
    int nameSum = 0;
    int pwSum = 0;
    int uniqueR = 0;
    int placeInTable = 0;

    // 1.) convert name and password to unique integer representation
    // accomplished by converting each character to ascii and adding up their values
    
    // convert name
    for (long unsigned int i = 0; i < name.length(); i++) {
        int asciiVal = (int)name[i] - MIN_ASCII_VAL;
        nameSum += asciiVal;
    }

    // convert pw
    for (long unsigned int i = 0; i < pass.length(); i++) {
        int asciiVal = (int)pass[i] - MIN_ASCII_VAL;
        pwSum += asciiVal;
    }

    // sum unique representations; name + pw
    uniqueR = nameSum + pwSum;

    // 2.) modulos unique integer
    placeInTable = (uniqueR % TABLE_SIZE);

    // 3.) scramble / encrypt the data before inserting
    std::string encryptedName = cipher.scramble(name);
    std::string encryptedPass = cipher.scramble(pass);

    // 4.) insert into table at unique spot, at tail of it's respective bucket / linked-list
    User temp(encryptedName, encryptedPass);
    table[placeInTable].insert(temp);

    return placeInTable;
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