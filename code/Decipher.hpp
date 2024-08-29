#ifndef H_DECIPHER
#define H_DECIPHER

#include <iostream>

class Decipher {
    public:
        Decipher();
        std::string getKey();
        void setKey(std::string);
        std::string decrypt(std::string);
    private:
        int const MIN_ASCII_VAL = 97;
        std::string key;
};

#endif