#pragma once
#include <string>

class InstructionConversion{
  private:
    static std::string instruction;
    static std::string address;

    static void halt();

  public:
    static int instr;
    static int addr;

    InstructionConversion() = default;

    // Methods
    static std::string determineIns();
    static void convert(int m);

    // Setters


};
