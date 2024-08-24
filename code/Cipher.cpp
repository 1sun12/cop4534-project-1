#include "Cipher.hpp"

Cipher::Cipher() {
    key = "jones";
    
    // length of key determines length of array
    int keyLgth = key.length();
    keyToInt = new int[keyLgth];
}

std::string Cipher::scramble(std::string wordToEncrypt) {
    // 1.) convert original key to integers in base 26 (0 - 25)

}