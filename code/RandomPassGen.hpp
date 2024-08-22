
#ifndef H_RANDOMPASSGEN
#define H_RANDOMPASSGEN

#include <iostream>
#include <cstdlib>

class RandomPassGen {
    public:
        RandomPassGen();
        std::string generateRandomPw();
    private:
        std::string password;
        char randomChar;
};

#endif