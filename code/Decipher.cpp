/***************************************************************
  Student Name:       Regan O'Donnell
  File Name:          Decipher.cpp
  Assignment number:  Project 1

    Responsible for decrypting the encrypted passwords in the hashtable
***************************************************************/

#include "Decipher.hpp"

Decipher::Decipher() {
    key = "";
}

std::string Decipher::getKey() {
    return key;
}

void Decipher::setKey(std::string a) {
    key = a;
}

std::string Decipher::decrypt(std::string wordToDecrypt) {
    int keyLgth = key.length();
    int keyToInt[keyLgth];
    int wordLgth = wordToDecrypt.length();
    int wordToInt[wordLgth];
    std::string finalString;

    // 1.) convert key to ascii values
    for (int i = 0; i < keyLgth; i++) {
        int asciiVal = (int)key[i] - MIN_ASCII_VAL;
        keyToInt[i] = asciiVal;
    }

    // 2.) convert wordToDecrypt also, to integers in base 26 (0 - 25); integer array
    for (int i = 0; i < wordLgth; i++) {
        int asciiVal = (int)wordToDecrypt[i] - MIN_ASCII_VAL;
        wordToInt[i] = asciiVal;
    }

    for (int i = 0; i < wordLgth; i++) {
        int sumOfAscii = wordToInt[i] - keyToInt[i % keyLgth];
        int sumMod26 = (sumOfAscii % 26 + 26) % 26;  // Handle negative modulus result
        finalString += (char)(sumMod26 + MIN_ASCII_VAL);
    }

    return finalString;
}