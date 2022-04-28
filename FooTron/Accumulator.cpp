#include "Accumulator.hh"
#include "ReadProgram.hh"

Accumulator::Accumulator(int i, int l) : instruction(i), location(l){}

Accumulator::Accumulator(){
  instruction = 0;
  location = 0;
}

Accumulator::readNextLine(){
  std::string str = ReadProgram::readNextLine();
  instruction = str.substring(0,2);
  location = str.substring(2);
}
