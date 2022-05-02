// Name: Patience Lamb
// Branching conditions to other lines

#include "BranchIns.hh"
#include "Accumulator.hh"
#include "Memory.hh"
#include "InstructionConversion.hh"

#include <iostream>

int BranchIns::addr = 0;
int BranchIns::instr = 0;


// Goes to address a where addr instruction+address is and
// calls convert on addr to be passed back into determineIns()
void BranchIns::branch(int a){
  addr = Memory::memory.at(a);
  InstructionConversion::convert(addr);
  InstructionConversion::determineIns();
}
// Goes to address a where addr instruction+address is and
// calls convert on addr to be passed back into determineIns() IFF accumulator
// value is less than zero
void BranchIns::branchNeg(int a){
  if(Accumulator::getLocation() < 0){
    addr = Memory::memory.at(a);
    InstructionConversion::convert(addr);
    InstructionConversion::determineIns();
  }
}

// Goes to address a where addr instruction+address is and
// calls convert on addr to be passed back into determineIns() IFF accumulator
// value is zero
void BranchIns::branchZero(int a){
  if(Accumulator::getLocation() == 0){
    addr = Memory::memory.at(a);
    InstructionConversion::convert(addr);
    InstructionConversion::determineIns();
  }
}
