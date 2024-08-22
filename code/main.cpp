/***************************************************************
  Student Name:
  File Name:
  Assignment number

  Other comments regarding the file - description of why it is there, etc.
***************************************************************/

#include "FileManager.hpp"
#include "RandomPassGen.hpp"

int main() {
  FileManager fm;
  RandomPassGen gm;

  //fm.printInputFile();
  std::string temp = gm.generateRandomPw();
  std::cout << temp << std::endl;

  return 0;
}