#pragma once
#include <string>

class InstructionConversion{
  private:
    static std::string instruction;
    static std::string address;

  public:
    static int instr;
    static int addr;

    InstructionConversion() = default;

    // Methods
    static std::string determineIns();
    static void convert(int m);
    static void halt();

    // Getters
    static std::string getIns(){ return instruction; }
    static std::string getAddr() { return address; }

};
