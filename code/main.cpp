/***************************************************************
  Student Name:
  File Name:
  Assignment number

  Other comments regarding the file - description of why it is there, etc.
***************************************************************/

#include "FileManager.hpp"
#include "RandomPassGen.hpp"
#include "Cipher.hpp"

int main() {
  FileManager fm;
  RandomPassGen gm;
  Cipher cp;

  //fm.printInputFile();
  //fm.writeRawData();
  cp.scramble("yahoo");

  return 0;
}