#include<iostream>
#include "UserDisplay.hh"
#include "InstructionConversion.hh"


void UserDisplay::printCurrentStep(){
  std::cout << "Executing: " << InstructionConversion::getIns() << " at " << InstructionConversion::getAddr() << std::endl;
  std::cout << "Press N to execute the next instruction" << std::endl;
  std::cout << "Press R to reset emulator" << std::endl;
  std::cout << "Press X to stop emulator" << std::endl;
}

void UserDisplay::printStartDisplay(){
  std::cout << "Please enter the file (including path) you wish to convert" << std::endl;
}

void UserDisplay::printEndDisplay(){
  std::cout << "Program has terminated at memory address " << InstructionConversion::getAddr() << std::endl;
}
