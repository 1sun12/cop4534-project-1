#include "Cipher.hpp"

Cipher::Cipher() {
    key = "jones";
    
    // length of key determines length of array
    keyLgth = key.length();
    keyToInt = new int[keyLgth];
}

Cipher::~Cipher() {
    delete[] keyToInt;
}

std::string Cipher::scramble(std::string wordToEncrypt) {
    // 1.) convert original key to integers in base 26 (0 - 25)
    for (int i = 0; i < keyLgth; i++) {
        int asciiVal = (int)key[i] - 97;
        std::cout << asciiVal << std::endl;
    }

    return "temp";
}