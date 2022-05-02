// Name: Patience Lamb
// Prints current step, the start display, and end display

#include<iostream>
#include "UserDisplay.hh"
#include "InstructionConversion.hh"

// Prints current step including instruction, address, and how the user can control
void UserDisplay::printCurrentStep(){
  std::cout << "Executing: " << InstructionConversion::getIns() << " at " << InstructionConversion::getAddr() << std::endl;
  std::cout << "Press N to execute the next instruction" << std::endl;
  std::cout << "Press R to reset emulator" << std::endl;
  std::cout << "Press X to stop emulator" << std::endl;
}

// Prints prompt to have user enter file path.
void UserDisplay::printStartDisplay(){
  std::cout << "Please enter the file (including path) you wish to convert" << std::endl;
}
// Prints prompt telling user where the program stopped.
void UserDisplay::printEndDisplay(){
  std::cout << "Program has terminated at memory address " << InstructionConversion::getAddr() << std::endl;
}
