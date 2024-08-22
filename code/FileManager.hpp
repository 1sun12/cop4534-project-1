#ifndef H_FILEMANAGER
#define H_FILEMANAGER

#include <fstream>
#include <iostream>
#include <sstream>
#include "RandomPassGen.hpp"

class FileManager {
    public:
        FileManager();
        void writeRawData();
        void printInputFile();
    private:
        std::ifstream ifs;
        std::ofstream ofs;
        std::istringstream iss;
        std::string inFile;
        std::string outRawFile;
        RandomPassGen rpg;
        
};

#endif