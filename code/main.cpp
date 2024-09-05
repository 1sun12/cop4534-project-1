/***************************************************************
  Student Name:       Regan O'Donnell
  File Name:          main.cpp
  Assignment number:  Project 1

  Other comments regarding the file - description of why it is there, etc.
***************************************************************/

#include "FileManager.hpp"
#include "HashTable.hpp"
#include "User.hpp"
#include "Cipher.hpp"

int main() {
  FileManager fm;
  HashTable ht;
  Cipher cp;

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

    // write entire hash-table to a file
    fm.writeEncryptedData(ht.toString());
  } 

  // Testing search
    std::cout << "searching smith: " << ht.search("smith").getName() << std::endl; // found
    std::cout << "searching brown: " << ht.search("brown").getName() << std::endl; // found
    std::cout << "searching asdf: " << ht.search("asdf").getName() << std::endl; // not found

  // print entire hash-table
  //ht.print();
  
  return 0;
}