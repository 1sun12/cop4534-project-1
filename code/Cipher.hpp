/***************************************************************
  Student Name:       Regan O'Donnell
  File Name:          Cipher.hpp
  Assignment number:  Project 1

    Cipher header file
***************************************************************/

#ifndef H_CIPHER
#define H_CIPHER

#include <iostream>
#include <cctype>
#include <algorithm>

class Cipher {
    public:
        Cipher();
        ~Cipher();
        std::string scramble(std::string);
        std::string toLower(std::string);
    private:
        int const MIN_ASCII_VAL = 97;
        std::string key;
        int keyLgth;
        int* keyToInt;  // dynamic; ascii values for key
        int wordLgth;
        int* wordToInt; // dynamic; ascii values for word-to-encrypt
};

#endif