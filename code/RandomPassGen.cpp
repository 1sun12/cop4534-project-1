/***************************************************************
  Student Name:       Regan O'Donnell
  File Name:          RandomPassGen.cpp
  Assignment number:  Project 1

    Responsible for generating random 9-character-lowercase passwords for each entry name in the input-txt file
***************************************************************/

#include "RandomPassGen.hpp"

RandomPassGen::RandomPassGen() {
    randomChar = 0;
    srand(time(0));
}

std::string RandomPassGen::generateRandomPw() {
    std::string password = "";
    for (int i = 0; i < 9; i++) {
        randomChar = rand() % 25 + 98;
        password += randomChar;
    }

    return password;
}