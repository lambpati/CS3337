// Name: Patience Lamb
// Adds, subtracts, divides, and multiplies from accumulator

#include "Arithmetic.hh"
#include "Accumulator.hh"
#include "Memory.hh"

int Arithmetic::value = 0;

// Adds value from memory location to the value stored in the accumulator and puts
// back into accumulator.
void Arithmetic::add(int a){
  value = Memory::getMemory(a);
  Accumulator::setLocation(value+Accumulator::getLocation());
}

// Subtracts value from memory location to the value stored in the accumulator and puts
// back into accumulator.
void Arithmetic::subtract(int a){
  value = Memory::getMemory(a);
  Accumulator::setLocation(Accumulator::getLocation()-value);
}

// Divides value from memory location to the value stored in the accumulator and puts
// back into accumulator.
void Arithmetic::divide(int a){
  value = Memory::getMemory(a);
  Accumulator::setLocation(Accumulator::getLocation()/value);
}

// Multiplies value from memory location to the value stored in the accumulator and puts
// back into accumulator.
void Arithmetic::multiply(int a){
  value = Memory::getMemory(a);
  Accumulator::setLocation(Accumulator::getLocation()*value);
}
