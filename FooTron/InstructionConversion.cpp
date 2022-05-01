#include <string>
#include "InstructionConversion.hh"
#include "readWriteLoadStore.hh"

#include "Arithmetic.hh"
#include "Memory.hh"
#include "ReadProgram.hh"
#include "UserControl.hh"

int InstructionConversion::instr;
int InstructionConversion::addr;
std::string InstructionConversion::instruction;
std::string InstructionConversion::address;

void InstructionConversion::convert(int memory){
  std::string str = std::to_string(memory);
  instruction = str.substr(0,2);
  address = str.substr(2);
  instr = std::stoi(instruction);
  addr = std::stoi(address);
}

void InstructionConversion::halt(){
  exit(0);
}

std::string InstructionConversion::determineIns(){
  // I hate this switch statement but it works
  switch (instr) {
    case 10 :
      readWriteLoadStore::read(addr);
      instruction = "ttRead";
      break;
    case 11 :
      readWriteLoadStore::write(addr);
      instruction = "ttWrite";
      break;
    case 20 :
    readWriteLoadStore::load(addr);
      instruction = "ttLoad";
      break;
    case 21 :
      readWriteLoadStore::store(addr);
      instruction = "ttStore";
      break;
    case 30 :
      Arithmetic::add(addr);
      instruction = "ttAdd";
      break;
    case 31 :
      Arithmetic::subtract(addr);
      instruction = "ttSubtract";
      break;
    case 32 :
      Arithmetic::divide(addr);
      instruction = "ttDivide";
      break;
    case 33 :
      Arithmetic::multiply(addr);
      instruction = "ttMultiply";
      break;
    case 40 :
      //branchIns::branch(a);
      instruction = "ttBranch";
      break;
    case 41 :
      //branchIns::branchNeg(a);
      instruction = "ttBranchNegative";
      break;
    case 42 :
      //branchIns::branchZero(a);
      instruction = "ttBranchZero";
      break;
    case 43 :
      InstructionConversion::halt();
      instruction = "ttHalt";
      break;
  }
  return instruction;
}
