#include "HashTable.hpp"

HashTable::HashTable() {
    table = new LinkedList[TABLE_SIZE]();
}

HashTable::~HashTable() {
    delete[] table;
}

int HashTable::insert(User user) {
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

    
    // 3.) scramble / encrypt the data before inserting
    std::string encryptedName = cipher.scramble(user.getName());
    std::string encryptedPass = cipher.scramble(user.getPw());

    // 4.) insert into table at unique spot, at tail of it's respective bucket / linked-list
    User temp(encryptedName, encryptedPass);
    table[placeInTable].insert(temp);

    return placeInTable;
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
    placeInTable = uniqueR % TABLE_SIZE;

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