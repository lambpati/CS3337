// Name: Patience Lamb
// Convert memory contents, determine instruction, and halt

#include <string>
#include "InstructionConversion.hh"
#include "readWriteLoadStore.hh"
#include "BranchIns.hh"
#include "Arithmetic.hh"
#include "ReadProgram.hh"
#include "WriteProgram.hh"

int InstructionConversion::instr;
int InstructionConversion::addr;
std::string InstructionConversion::instruction;
std::string InstructionConversion::address;


// Convert from memory contents to instruction and addresse
void InstructionConversion::convert(int memory){
  std::string str = std::to_string(memory);
  instruction = str.substr(0,2);
  address = str.substr(2);
  instr = std::stoi(instruction);
  addr = std::stoi(address);
}

// Stop program and write WrittenValues array to output
void InstructionConversion::halt(){
  WriteProgram::writeToOutput(readWriteLoadStore::getWrittenValues());
}

// Determine the instruction to be executed, and return the instruction after being
// executed.
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
      BranchIns::branch(addr);
      instruction = "ttBranch";
      break;
    case 41 :
      BranchIns::branchNeg(addr);
      instruction = "ttBranchNegative";
      break;
    case 42 :
      BranchIns::branchZero(addr);
      instruction = "ttBranchZero";
      break;
    case 43 :
      instruction = "ttHalt";
      InstructionConversion::halt();
      break;
  }
  return instruction;
}
