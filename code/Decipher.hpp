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
        std::string key;
};

#endif