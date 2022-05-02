// Name: Patience Lamb
// Reads, writes, loads, and stores values to/from memory

#include "readWriteLoadStore.hh"
#include "Accumulator.hh"
#include "Memory.hh"
#include "WriteProgram.hh"
#include<iostream>

int readWriteLoadStore::value;
std::vector<int> readWriteLoadStore::writtenValues;

// Reads values from keyboard and pushes it to specified memory location
void readWriteLoadStore::read(int a){
  std::cout << "Enter value for reading: ";
  std::cin >> value;
  Memory::setMemory(a, value);
}

// Writes values from memory to an array of written values to be output in a file
void readWriteLoadStore::write(int a){
  value = Memory::getMemory(a);
  writtenValues.push_back(value);
  std::cout << "value written: " << value << std::endl;
}

// Loads values from memory to the accumulator from specified memory location
void readWriteLoadStore::load(int a){
  value = Memory::getMemory(a);
  Accumulator::setLocation(value);
}

// Stores values from accumulator to specified memory location
void readWriteLoadStore::store(int a){
  value = Accumulator::getLocation();
  Memory::setMemory(a, value);
}
