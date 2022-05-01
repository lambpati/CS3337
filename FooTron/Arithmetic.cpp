#include "Arithmetic.hh"
#include "Accumulator.hh"
#include "Memory.hh"

int Arithmetic::value = 0;

void Arithmetic::add(int a){
  value = Memory::getMemory(a);
  Accumulator::setLocation(value+Accumulator::getLocation());
}

void Arithmetic::subtract(int a){
  value = Memory::getMemory(a);
  Accumulator::setLocation(Accumulator::getLocation()-value);
}

void Arithmetic::divide(int a){
  value = Memory::getMemory(a);
  Accumulator::setLocation(Accumulator::getLocation()/value);
}

void Arithmetic::multiply(int a){
  value = Memory::getMemory(a);
  Accumulator::setLocation(Accumulator::getLocation()*value);
}
