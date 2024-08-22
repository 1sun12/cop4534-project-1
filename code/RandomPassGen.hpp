
#ifndef H_RANDOMPASSGEN
#define H_RANDOMPASSGEN

#include <iostream>
#include <cstdlib>

class RandomPassGen {
    public:
        RandomPassGen();
        std::string generateRandomPw(std::string);
    private:
        std::string password;
        int randNumber;
};

#endif