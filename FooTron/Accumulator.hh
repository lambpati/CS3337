// Parses out the instructions from the contents as well as the location
#pragma once

class Accumulator{
  private:
    int instruction;
    int location;
  public:
    Accumulator(int, int);
    Accumulator();

    // Methods
    void parseLine();

    // Getters
    int getInstruction const(){ return instruction; }
    int getLocation const(){ return location; }
};
