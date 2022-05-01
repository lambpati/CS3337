#include<iostream>

#include "readWriteLoadStore.hh"
#include "Accumulator.hh"
#include "Memory.hh"
#include "WriteProgram.hh"

int readWriteLoadStore::value;
std::vector<int> readWriteLoadStore::writtenValues;

void readWriteLoadStore::read(int a){
  std::cout << "Enter value for reading: ";
  std::cin >> value;
  Memory::setMemory(a, value);
}

void readWriteLoadStore::write(int a){
  value = Memory::getMemory(a);
  writtenValues.push_back(value);
  //WriteProgram::writeToOutput(value);
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
