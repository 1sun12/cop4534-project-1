/***************************************************************
  Student Name:       Regan O'Donnell
  File Name:          RandomPassGen.hpp
  Assignment number:  Project 1

    RandomPassGen header file
***************************************************************/

#ifndef H_RANDOMPASSGEN
#define H_RANDOMPASSGEN

#include <iostream>
#include <cstdlib>

class RandomPassGen {
    public:
        RandomPassGen();
        std::string generateRandomPw();
    private:
        char randomChar;
};

#endif