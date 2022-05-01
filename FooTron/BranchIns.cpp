#include "BranchIns.hh"
#include "Accumulator.hh"
#include "Memory.hh"
#include "InstructionConversion.hh"

int BranchIns::addr = 0;

void BranchIns::branch(int a){
  addr = Memory::memory.at(a);
  InstructionConversion::convert(a);
  InstructionConversion::determineIns();
}

void BranchIns::branchNeg(int a){
  if(Accumulator::getLocation() < 0){
    addr = Memory::memory.at(a);
    InstructionConversion::convert(a);
    InstructionConversion::determineIns();
  }
}

void BranchIns::branchZero(int a){
  if(Accumulator::getLocation() == 0){
    addr = Memory::memory.at(a);
    InstructionConversion::convert(a);
    InstructionConversion::determineIns();
  }
}
