
#include "RandomPassGen.hpp"

RandomPassGen::RandomPassGen() {
    password = "";
    randomChar = 0;
    srand(time(0));
}

std::string RandomPassGen::generateRandomPw() {
    for (int i = 0; i < 9; i++) {
        randomChar = rand() % 25 + 98;
        password += randomChar;
    }

    return password;
}