
#include "FileManager.hpp"

FileManager::FileManager() {
    openInputFile();

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
    ofs.close();
    ofs.open(OUT_RAW_DATA);

    // write all input file data to rawdata
    while(std::getline(ifs, currLine)) {
        iss.str(currLine);
        iss.clear();
        iss >> currName;
        password = rpg.generateRandomPw();
    
        ofs << currName << " " << password << std::endl;
    }
}

void FileManager::writeEncryptedData(std::string data) {
    ofs.close();
    ofs.open(OUT_ENCRYPTED_DATA);

    ofs << data;
}

std::string FileManager::getLineRawData() {
    std::string line = "";
    getline(ifs, line);
    if (!ifs) {
        return "0";
    } else {
        return line;
    }
}

std::string FileManager::getSpecificLineRawData(int lineNumber) {
    std::string line = "";
    ifs.close();
    ifs.open(IN_RAW_DATA);
    for (int i = 0; i < lineNumber - 1; i++) {
        getline(ifs, line);
    }

    // grab the line we want
    getline(ifs, line);

    return line;
}

void FileManager::openInputFile() {
    ifs.close();
    ifs.open(IN_FILE);
}

void FileManager::openRawData() {
    ifs.close();
    ifs.open(IN_RAW_DATA);
}

void FileManager::printInputFile() {
    std::string currLine = "";
    while(std::getline(ifs, currLine)) {
        std::cout << currLine << std::endl;
    }
}