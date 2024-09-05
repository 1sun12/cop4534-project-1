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

std::string const NAME1 = "smith", NAME3 = "williams", NAME5 = "brown", NAME7 = "miller", NAME9 = "moore";

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
  } 

  // writing to encrypted output file
    std::string encOut = "";

    User user1 = ht.search(NAME1);
    User user3 = ht.search(NAME3);
    User user5 = ht.search(NAME5);
    User user7 = ht.search(NAME7);
    User user9 = ht.search(NAME9);

    encOut += user1.getName() + " " + user1.getPw() + "\n";
    encOut += user3.getName() + " " + user3.getPw() + "\n";
    encOut += user5.getName() + " " + user5.getPw() + "\n";
    encOut += user7.getName() + " " + user7.getPw() + "\n";
    encOut += user9.getName() + " " + user9.getPw() + "\n";

    //fm.writeEncryptedData(encOut);

    // ================================================================
    // =========================LEGAL==================================
    std::cout << "~ Legal ~\n\n";
    std::cout << "User\tPw(file)\tPw(table)\tResult";
  
  return 0;
}