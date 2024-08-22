
#include "FileManager.hpp"

FileManager::FileManager() {
    inFile = "../names.txt";
    outRawFile = "rawdata.txt";

    ifs.open(inFile);

    while (!ifs.is_open()) {
        std::cout << "Input File not found, could you attempt to type it?\n$ File: ";
        std::string fileName;
        std::cin >> fileName;
        ifs.open(fileName);
    }
}

void FileManager::writeRawData() {
    std::string currLine = "";
    std::string currName = "";
    std::string password = "";
    ofs.open(outRawFile);

    // write the first 20 lines
    for (int i = 0; i < 20; i++){
        std::getline(ifs, currLine);
        iss.str(currLine);
        iss.clear();
        iss >> currName;
        password = rpg.generateRandomPw();

        ofs << currName << " " << password << std::endl;
    }

}

void FileManager::printInputFile() {
    std::string currLine = "";
    while(std::getline(ifs, currLine)) {
        std::cout << currLine << std::endl;
    }
}