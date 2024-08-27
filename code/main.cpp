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

int main() {
  FileManager fm;
  RandomPassGen gm;
  Cipher cp;
  HashTable ht;
  User tempUser; tempUser.setName("bob"); tempUser.setPw("abcwerkjdfo");

  //fm.printInputFile();
  //fm.writeRawData();
  std::cout << cp.scramble("banana") << std::endl;

  ht.insert(tempUser);

  return 0;
}