#include<iostream>
#include "UserDisplay.hh"


void UserDisplay::printCurrentStep(){
  std::cout << "Executing: " << currentIns << " at " << currentAddr << std::endl;
  std::cout << "Next instruction: " << nextIns << " at " << nextAddr << " from line " << std::endl;
  std::cout << "Press ENTER to execute the next instruction" << std::endl;
  std::cout << "Press X to reset emulator" << std::endl;
}

void UserDisplay::printStartDisplay(){
  std::cout << "Please enter the file (including path) you wish to convert" << std::endl;
}

void UserDisplay::printEndDisplay(){
  std::cout << "File has terminated. " << std::endl;
}
