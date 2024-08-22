#ifndef H_FILEMANAGER
#define H_FILEMANAGER

#include <fstream>
#include <iostream>

class FileManager {
    public:
        FileManager();
        std::string nextLine();
        void printInputFile();
    private:
        std::ifstream ifs;
        std::ofstream ofs;
};

#endif