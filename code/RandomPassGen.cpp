
#include "RandomPassGen.hpp"

RandomPassGen::RandomPassGen() {
    password = "";
    randomChar = 0;
}

std::string RandomPassGen::generateRandomPw() {
    for (int i = 0; i < 9; i++) {
        randomChar = rand() % 126 + 1;
        password += randomChar;
        std::cout << password << std::endl;
    }

    return password;
}