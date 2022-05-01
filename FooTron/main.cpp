#include "UserDisplay.hh"
#include "UserControl.hh"
#include "InstructionConversion.hh"
#include "readWriteLoadStore.hh"

#include "Arithmetic.hh"
#include "Memory.hh"
#include "ReadProgram.hh"
#include "UserControl.hh"
#include <string>
#include <iostream>
#include <unistd.h>
#include <stdio.h>



int main(int argc, char const *argv[]) {
  UserDisplay::printStartDisplay();
  // For debugging and pwd purposes
  char cwd[1024];
  chdir("/path/to/change/directory/to");
  getcwd(cwd, sizeof(cwd));
  printf("Current working dir: %s\n", cwd);

  // Path according to build folder
  UserControl::setFileName("../Examples/footronSample1.txt");

  ReadProgram::read();

  for(int a = 0; a < ReadProgram::getLineNum(); a++){
    InstructionConversion::convert(Memory::getMemory(a));
    std::cout << InstructionConversion::determineIns();
  }

  return 0;
}
