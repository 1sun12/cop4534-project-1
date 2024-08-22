#ifndef H_FILEMANAGER
#define H_FILEMANAGER

#include <fstream>
#include <iostream>

class FileManager {
    public:
        FileManager();
        void printInputFile();
    private:
        std::ifstream ifs;
        std::ofstream ofs;
};

#endif