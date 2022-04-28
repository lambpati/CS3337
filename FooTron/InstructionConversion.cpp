#pragma once

class InstructionConversion{
  private:
    std::string instr;
    int address;

    // Private methods because no access
    void readIns(int a);
    void writeIns(int a);
    void loadIns(int a);
    void storeIns(int a);
    void addIns(int a);
    void subtractIns(int a);
    void divideIns(int a);
    void branchIns(int a);
    void branchNeg(int a);
    void branchZero(int a);
    void halt();

  public:
    InstructionConversion();

    // Methods
    std::string determineIns(int i, int a);

};
