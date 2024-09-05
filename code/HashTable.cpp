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

    // insert into table at unique hash
    User temp(user.getName(), encryptedPass);
    table[placeInTable].insert(temp);

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

User HashTable::search(std::string name) {
    int indexInHashTable = hash(name);
    return searchHelper(table[indexInHashTable].getHead(), name);    
}

User HashTable::searchHelper(Node* head, std::string name) {
    std::string tempN = "NOT FOUND", tempP = "NO PASS";

    if (head == nullptr) {                  // return if head is null
        return User(tempN, tempP);
    }

    if (head->data.getName() == name) {     // return if we FOUND user
        return head->data;
    } 

    // Continue searching if next is not null
    if (head->next != nullptr) {
        return searchHelper(head->next, name);  // Return the result of the recursive call
    } 

    // Not found, return default
    return User(tempN, tempP);
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

    int indexInHashTable = sum % TABLE_SIZE;

    return indexInHashTable;
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

std::string HashTable::toString() {
    std::string tooString = "";
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i].getHead() != nullptr) {
            tooString += table[i].toString() + "\n";
        }
    }

    return tooString;
}