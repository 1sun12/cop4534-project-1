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

int main() {
  FileManager fm;
  RandomPassGen gm;
  Cipher cp;
  HashTable ht;
  User tempUser0; tempUser0.setName("bob"); tempUser0.setPw("abcwerkjdfo");
  User tempUser1; tempUser1.setName("job"); tempUser1.setPw("abcwerkoiwe");
  User tempUser2; tempUser2.setName("rob"); tempUser2.setPw("absdlfkjllk");
  LinkedList ll;

  //fm.printInputFile();
  //fm.writeRawData();
  //std::cout << cp.scramble("banana") << std::endl;

  //ht.insert(tempUser);

  int somePlaceInTable0 = ht.insert(tempUser0);
  int somePlaceInTable1 = ht.insert(tempUser1);
  ht.insert(tempUser0);

  std::cout << "Place: " << somePlaceInTable0 << std::endl;
  std::cout << "Data {\n"; ht.printAt(somePlaceInTable0); std::cout << "}";

  std::cout << "Place: " << somePlaceInTable1 << std::endl;
  std::cout << "Data {\n"; ht.printAt(somePlaceInTable1); std::cout << "}";

  return 0;
}