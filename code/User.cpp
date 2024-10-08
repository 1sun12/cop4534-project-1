/***************************************************************
  Student Name:       Regan O'Donnell
  File Name:          User.cpp
  Assignment number:  Project 1

    Data-container-like object class that helped me store names and passwords. A node in my linked-list is one of these user objects
***************************************************************/

#include "User.hpp"

User::User() {
    this->name = "";
    this->password = "";
}

User::User(std::string a, std::string b) {
    this->name = a;
    this->password = b;
}

std::string User::getName() {
    return this->name;
}

std::string User::getPw() {
    return this->password;
}

void User::setName(std::string a) {
    this->name = a;
}

void User::setPw(std::string a) {
    this->password = a;
}

void User::print() {
    std::cout << "\t\tUsername: " << "\t\t" + getName() << std::endl;
    std::cout << "\t\tPassword: " << "\t\t" + getPw() << std::endl;
}

std::string User::toString() {
    std::string tooString = "";
    tooString += getName() + " " + getPw();
    return tooString;
}