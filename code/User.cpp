#include "User.hpp"

User::User() {
    this->name = "";
    this->password = "";
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