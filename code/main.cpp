/***************************************************************
  Student Name:
  File Name:
  Assignment number

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
    std::string line = fm.getLineRawData();
    // eof was reached; break loop
    if (line == "0") {break;}
    std::istringstream iss(line);
    std::string name, pass;
    iss >> name >> pass;
    
    // convert name to all lower-case
    name = cp.toLower(name);

    std::string encName = cp.scramble(name);
    std::string encPass = cp.scramble(pass);

    // print decryption to terminal
    dp.setKey("jones");
    std::cout << "encryption: " << name << std::endl;
    std::cout << "decryption: " << dp.decrypt(encName) << std::endl;

    User user(encName, encPass);

    ht.insert(user);
  }

  ht.print();
  
  return 0;
}