
#include "FileManager.hpp"

FileManager::FileManager() {
    ifs.open("../names.txt");

    while (!ifs.is_open()) {
        std::cout << "Input File not found, could you attempt to type it?\nFile: ";
        std::string fileName;
        std::cin >> fileName;
        ifs.open(fileName);
    }
}

void FileManager::printInputFile() {
    std::string currLine = "";
    while(std::getline(ifs, currLine)) {
        std::cout << currLine << std::endl;
    }
}