#include<iostream>

#include "readWriteLoadStore.hh"
#include "Accumulator.hh"
#include "Memory.hh"

int readWriteLoadStore::value;

void readWriteLoadStore::read(int a){
  std::cout << "Enter value for reading: ";
  std::cin >> value;
  Memory::setMemory(a, value);
}

void readWriteLoadStore::write(int a){
  value = Memory::getMemory(a);
  std::cout << "value written: " << value << std::endl;
}

void readWriteLoadStore::load(int a){
  value = Memory::getMemory(a);
  Accumulator::setLocation(value);
}

void readWriteLoadStore::store(int a){
  value = Accumulator::getLocation();
  Memory::setMemory(a, value);
}
