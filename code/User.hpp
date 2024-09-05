/***************************************************************
  Student Name:       Regan O'Donnell
  File Name:          User.hpp
  Assignment number:  Project 1

    User header file
***************************************************************/

#ifndef H_USER
#define H_USER

#include <iostream>

// data container class
class User { 
    public:
        User();
        User(std::string, std::string);
        std::string getName();
        std::string getPw();
        void setName(std::string);
        void setPw(std::string);
        void print();
        std::string toString();
    private:
        std::string name;
        std::string password;
};

#endif