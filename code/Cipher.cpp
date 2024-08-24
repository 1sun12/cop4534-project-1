#include "Cipher.hpp"

Cipher::Cipher() {
    key = "jones";
    keyLgth = 0;
    wordLgth = 0;
    
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
        int asciiVal = (int)key[i] - MIN_ASCII_VAL;
        keyToInt[i] = asciiVal;
        std::cout << asciiVal << std::endl;
    }

    // 2.) convert word-to-encrypt also, to integers in base 26 (0 - 25); integer array
    wordLgth = wordToEncrypt.length();
    for (int i = 0; i < wordLgth; i++) {
        int asciiVal = (int)wordToEncrypt[i] - MIN_ASCII_VAL;
        wordToInt[i] = asciiVal;
    }

    // 3.) both the key and word are in ascii form; add their values and mod 26
    // this would be for the duration of the word, not the key
    // the key can only be summed for however many characters the word had
    // ~ Example ~
    // b o b l o v e s a p p l e s
    // j o n e s j o n e s j o n e
    // --> ascii values
    // 1 14 1 11 14 21 4 18 0 15 15 11 4 18
    // 9 14 13 4 18 9 14 13 4 18 9 14 13 4
    // + ----------------------------------
    // = 10 28 14 15 32 30 18 31 4 33 26 27 17 22
    // mod 26 -------------------------------
    // = 10 2 14 15 6 4 18 5 4 7 0 1 17 22
    // --> convert back to string (add 97)
    // k c o p g g s f e h a b r w
    // encrypted word: bob loves apples --> kcopggsfehabrw
    for (int i = 0; i < wordLgth; i++) {

    }
    return "temp";
}