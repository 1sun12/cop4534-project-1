/***************************************************************
  Student Name:       Regan O'Donnell
  File Name:          FileManager.hpp
  Assignment number:  Project 1

    FileManager header file
***************************************************************/

#ifndef H_FILEMANAGER
#define H_FILEMANAGER

#include <fstream>
#include <iostream>
#include <sstream>
#include "RandomPassGen.hpp"
#include "HashTable.hpp"

class FileManager {
    public:
        FileManager();
        void writeRawData();
        void writeEncryptedData(std::string);
        std::string getLineRawData();
        std::string getSpecificLineRawData(int);
        void openRawData();
        void openInputFile();
        void printInputFile();
    private:
        std::ifstream ifs;
        std::ofstream ofs;
        std::istringstream iss;
        std::string IN_FILE = "../names.txt";
        std::string IN_RAW_DATA = "rawdata.txt";
        std::string OUT_RAW_DATA = "rawdata.txt";
        std::string IN_ENCRYPTED_DATA = "encrypteddata.txt";
        std::string OUT_ENCRYPTED_DATA = "encrypteddata.txt";
        RandomPassGen rpg;

    //     inFile = "../names.txt";
    // inRawData = "rawdata.txt";
    // outRawFile = "rawdata.txt";
        
};

#endif