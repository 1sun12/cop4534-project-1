#ifndef H_CIPHER
#define H_CIPHER

#include <iostream>
class Cipher {
    public:
        Cipher();
        ~Cipher();
        std::string scramble(std::string);
    private:
        int const MIN_ASCII_VAL = 97;
        std::string key;
        int keyLgth;
        int* keyToInt;  // dynamic; ascii values for key
        int wordLgth;
        int* wordToInt; // dynamic; ascii values for word-to-encrypt
};

#endif