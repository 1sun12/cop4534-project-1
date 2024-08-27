
#ifndef H_USER
#define H_USER

#include <iostream>

// data container class
class User { 
    public:
        User();
        std::string getName();
        std::string getPw();
        void setName(std::string);
        void setPw(std::string);
        void print();
    private:
        std::string name;
        std::string password;
};

#endif