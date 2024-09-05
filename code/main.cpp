/***************************************************************
  Student Name:       Regan O'Donnell
  File Name:          main.cpp
  Assignment number:  Project 1

  All classes are collected here, tested, with results printed to the terminal
***************************************************************/

#include "FileManager.hpp"
#include "HashTable.hpp"
#include "User.hpp"
#include "Cipher.hpp"
#include "Decipher.hpp"

std::string const NAME1 = "smith", NAME3 = "williams", NAME5 = "brown", NAME7 = "miller", NAME9 = "moore";

int main() {
  FileManager fm;
  HashTable ht;
  Cipher cp;
  Decipher dp;
  dp.setKey("jones");

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

    // writing to encrypted output file...
    std::string encOut = "";

    User user1_table = ht.search(NAME1);
    User user3_table = ht.search(NAME3);
    User user5_table = ht.search(NAME5);
    User user7_table = ht.search(NAME7);
    User user9_table = ht.search(NAME9);

    encOut += user1_table.getName() + " " + user1_table.getPw() + "\n";
    encOut += user3_table.getName() + " " + user3_table.getPw() + "\n";
    encOut += user5_table.getName() + " " + user5_table.getPw() + "\n";
    encOut += user7_table.getName() + " " + user7_table.getPw() + "\n";
    encOut += user9_table.getName() + " " + user9_table.getPw();

    // ...writing to encrypted file
    fm.writeEncryptedData(encOut);

    // creating rawdata.txt users...
    std::string line = fm.getSpecificLineRawData(1), rawName = "", rawPw = "";
    std::istringstream iss(line); iss >> rawName >> rawPw; iss.clear();
    User user1_rawData = User(rawName, rawPw);
    
    line = fm.getSpecificLineRawData(3);
    iss.str(line); iss >> rawName >> rawPw; iss.clear(); 
    User user3_rawData = User(rawName, rawPw);

    line = fm.getSpecificLineRawData(5);
    iss.str(line); iss >> rawName >> rawPw; iss.clear(); 
    User user5_rawData = User(rawName, rawPw);

    line = fm.getSpecificLineRawData(7);
    iss.str(line); iss >> rawName >> rawPw; iss.clear(); 
    User user7_rawData = User(rawName, rawPw);

    line = fm.getSpecificLineRawData(9);
    iss.str(line); iss >> rawName >> rawPw; iss.clear(); 
    User user9_rawData = User(rawName, rawPw);
    // ...creating rawdata.txt users

    // calculating the results of the rawdata.txt, and the information from the table
    // lets see if they match!
    bool legalResult1 = false, legalResult3 = false, legalResult5 = false, legalResult7 = false, legalResult9 = false;
    if (user1_rawData.getPw() == dp.decrypt(user1_table.getPw())) {legalResult1 = true;}
    if (user3_rawData.getPw() == dp.decrypt(user3_table.getPw())) {legalResult3 = true;}
    if (user5_rawData.getPw() == dp.decrypt(user5_table.getPw())) {legalResult5 = true;}
    if (user7_rawData.getPw() == dp.decrypt(user7_table.getPw())) {legalResult7 = true;}
    if (user9_rawData.getPw() == dp.decrypt(user9_table.getPw())) {legalResult9 = true;}

    // ================================================================================================================
    // =========================LEGAL==================================================================================
    std::cout << "\n\n~ Legal ~\n\n";
    std::cout << "User\t\tPw(file)\t\tPw(table)\t\tResult\n";
    std::cout << NAME1 << "\t\t" + user1_rawData.getPw() << "\t\t" + dp.decrypt(user1_table.getPw()) << "\t\t" << legalResult1 << "\n";
    std::cout << NAME3 << "\t" + user3_rawData.getPw() << "\t\t" + dp.decrypt(user3_table.getPw()) << "\t\t" << legalResult3 << "\n";
    std::cout << NAME5 << "\t\t" + user5_rawData.getPw() << "\t\t" + dp.decrypt(user5_table.getPw()) << "\t\t" << legalResult5 << "\n";
    std::cout << NAME7 << "\t\t" + user7_rawData.getPw() << "\t\t" + dp.decrypt(user7_table.getPw()) << "\t\t" << legalResult7 << "\n";
    std::cout << NAME9 << "\t\t" + user9_rawData.getPw() << "\t\t" + dp.decrypt(user9_table.getPw()) << "\t\t" << legalResult9 << "\n";
    
    // ================================================================================================================
    // ==========================ILLEGAL===============================================================================
    // first I gotta retreive the passwords, decrypt them, change a letter, then re-encrypt them...
    std::string illPw1 = dp.decrypt(user1_table.getPw()), illPw3 = dp.decrypt(user3_table.getPw()), illPw5 = dp.decrypt(user5_table.getPw()), illPw7 = dp.decrypt(user7_table.getPw()), illPw9 = dp.decrypt(user9_table.getPw());
    illPw1[0] = (illPw1[0] + 2) % 26; illPw3[0] = (illPw3[0] + 2) % 26; illPw5[0] = (illPw5[0] + 2) % 26; illPw7[0] = (illPw7[0] + 2) % 26; illPw9[0] = (illPw9[0] + 2) % 26;
    illPw1 = cp.scramble(illPw1); illPw3 = cp.scramble(illPw3); illPw5 = cp.scramble(illPw5); illPw7 = cp.scramble(illPw7); illPw9 = cp.scramble(illPw9);

    // calculating illegal matches
    bool illResult1 = false, illResult3 = false, illResult5 = false, illResult7 = false, illResult9 = false;
    if (user1_rawData.getPw() == dp.decrypt(illPw1)) {illResult1 = true;}
    if (user3_rawData.getPw() == dp.decrypt(illPw1)) {illResult3 = true;}
    if (user5_rawData.getPw() == dp.decrypt(illPw1)) {illResult5 = true;}
    if (user7_rawData.getPw() == dp.decrypt(illPw1)) {illResult7 = true;}
    if (user9_rawData.getPw() == dp.decrypt(illPw1)) {illResult9 = true;}

    // printing illegal results
    std::cout << "\n\n~ Illegal ~\n\n";
    std::cout << "User\t\tPw(file)\t\tPw(table)\t\tResult\n";
    std::cout << NAME1 << "\t\t" + user1_rawData.getPw() << "\t\t" + dp.decrypt(illPw1) << "\t\t" << illResult1 << "\n";
    std::cout << NAME3 << "\t" + user3_rawData.getPw() << "\t\t" + dp.decrypt(illPw3) << "\t\t" << illResult3 << "\n";
    std::cout << NAME5 << "\t\t" + user5_rawData.getPw() << "\t\t" + dp.decrypt(illPw5) << "\t\t" << illResult5 << "\n";
    std::cout << NAME7 << "\t\t" + user7_rawData.getPw() << "\t\t" + dp.decrypt(illPw7) << "\t\t" << illResult7 << "\n";
    std::cout << NAME9 << "\t\t" + user9_rawData.getPw() << "\t\t" + dp.decrypt(illPw9) << "\t\t" << illResult9 << "\n";

    std::cout << "\n\n";
 
  return 0;
}