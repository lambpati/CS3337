#pragma once

class BranchIns{
  private:
    static int addr;
    static int instr;
    
  public:
    BranchIns() = default;

    // Methods
    static void branch(int a);
    static void branchNeg(int a);
    static void branchZero(int a);
};
