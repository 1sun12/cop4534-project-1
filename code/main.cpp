/***************************************************************
  Student Name:       Regan O'Donnell
  File Name:          main.cpp
  Assignment number:  Project 1

  Other comments regarding the file - description of why it is there, etc.
***************************************************************/

#include "FileManager.hpp"
#include "RandomPassGen.hpp"
#include "Cipher.hpp"
#include "HashTable.hpp"
#include "User.hpp"
#include "LinkedList.hpp"
#include "Decipher.hpp"

int main() {
  FileManager fm;
  RandomPassGen gm;
  Cipher cp;
  HashTable ht;
  LinkedList ll;
  Decipher dp;

  fm.writeRawData();
  fm.openRawData();

  while(true) {
    // get line in raw-data.txt
    std::string line = fm.getLineRawData();

    // eof was reached; break loop
    if (line == "0") {break;}

    // create a string stream to seperate line by white-space
    std::istringstream iss(line);
    std::string name, pass;
    iss >> name >> pass;
    
    // convert name to all lower-case (if necessary)
    name = cp.toLower(name);

    // create User-obj with name and randomly generated password
    User user (name, pass);

    // insert into hash-table
    ht.insert(user);
  }

  // print entire hash-table
  ht.print();
  
  return 0;
}