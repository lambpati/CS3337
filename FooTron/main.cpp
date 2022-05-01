#include "UserDisplay.hh"
#include "UserControl.hh"
#include "InstructionConversion.hh"
#include "Memory.hh"
#include "ReadProgram.hh"

#include <string>
#include <iostream>
#include <unistd.h>
#include <stdio.h>

// Paths relative to build folder
// ../Examples/footronSample1.txt
// ../Examples/footronSample2.txt
// ../Examples/footronSample3.txt


int main(int argc, char const *argv[]) {
  int a = 0;
  UserDisplay::printStartDisplay();
  // For debugging and pwd purposes
  char cwd[1024];
  chdir("/path/to/change/directory/to");
  getcwd(cwd, sizeof(cwd));
  printf("Current working dir: %s\n", cwd);

  std::string name;
  std::cin >> name;

  UserControl::setFileName(name);

  ReadProgram::read();
  InstructionConversion::convert(Memory::getMemory(a));
  InstructionConversion::determineIns();
  UserDisplay::printCurrentStep();
  a++;

try{
    while(!UserControl::getStop() && InstructionConversion::getIns() != "ttHalt"){
      UserControl::DetermineControl();
      if(UserControl::getNext()){
        InstructionConversion::convert(Memory::getMemory(a));
        InstructionConversion::determineIns();
        UserDisplay::printCurrentStep();
        a++;
      }
      else if(UserControl::getRestart()){
        a = 0;
        ReadProgram::read();
        InstructionConversion::convert(Memory::getMemory(a));
        InstructionConversion::determineIns();
        UserDisplay::printCurrentStep();
        a++;
      }
      else if(UserControl::getStop()){
        InstructionConversion::halt();
      }
    }
    UserDisplay::printEndDisplay();
  }
  catch(const std::out_of_range& e){
    UserDisplay::printEndDisplay();
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
