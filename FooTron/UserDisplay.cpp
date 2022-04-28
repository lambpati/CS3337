#include "UserDisplay.hh"

UserDisplay::UserDisplay(int cA, int nA, std::string cI, std::string nI, int mA, int cN, int lN) :
currentAddr(cA), nextAddr(nA), currentIns(cI), nextIns(nI), memoryAmt(mA), counterNum(cN), lineNum(lN){}

UserDisplay::UserDisplay(){}

UserDisplay::printCurrentStep(){
  std::cout << "Executing: " << currentIns << " at " << currentAddr << " from line "  << lineNum << std::endl;
  std::cout << "Next instruction: " << nextIns << " at " << nextAddr << " from line " << lineNum << std::endl;
  std::cout << "Press ENTER to execute the next instruction" << std::endl;
  std::cout << "Press X to reset emulator" << std::endl;
}

UserDisplay::printStartDisplay(){
  "Please enter the file (including path) you wish to convert" << std::endl;
}

UserDisplay::printEndDisplay(){
  "File has terminated at " << lineNum << " output has been written to output.txt" << std::endl;
}

int main(int argc, char const *argv[]) {
  UserDisplay::printStartDisplay();


  return 0;
}
