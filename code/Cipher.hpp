#ifndef H_CIPHER
#define H_CIPHER

#include <iostream>
class Cipher {
    public:
        Cipher();
        ~Cipher();
        std::string scramble(std::string);
    private:
        std::string key;
        int keyLgth;
        int* keyToInt; // dynamic allocated array of integers
};

#endif