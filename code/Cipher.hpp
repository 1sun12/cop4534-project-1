#ifndef H_CIPHER
#define H_CIPHER

#include <iostream>
class Cipher {
    public:
        Cipher();
        std::string generateKey();
        std::string cipher();
    private:
};

#endif