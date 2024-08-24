#include "Cipher.hpp"

Cipher::Cipher() {
    key = "jones";
    
    // length of key determines length of array
    keyLgth = key.length();
    keyToInt = new int[keyLgth];
}

Cipher::~Cipher() {
    if (keyToInt != nullptr) {
        delete[] keyToInt;
    }

    if (wordToInt != nullptr) {
        delete[] wordToInt;
    }
}

std::string Cipher::scramble(std::string wordToEncrypt) {
    // 1.) convert original key to integers in base 26 (0 - 25); integer array
    for (int i = 0; i < keyLgth; i++) {
        int asciiVal = (int)key[i] - 97;
        keyToInt[i] = asciiVal;
    }

    // 2.) convert word-to-encrypt also, to integers in base 26 (0 - 25); integer array

    return "temp";
}