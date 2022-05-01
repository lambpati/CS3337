#pragma once
#include <string>

class UserDisplay{
  private:
    int currentAddr;
    int nextAddr;
    std::string currentIns;
    std::string nextIns;
    int memoryAmt;
    int counterNum;

  public:
    UserDisplay() = default;

    // Setters
    void setCurrentAddr(int a){ currentAddr = a; }
    void setNextAddr(int a){ nextAddr = a; }
    void setCurrentIns(std::string s){ currentIns = s; }
    void setNextIns(std::string s){ nextIns = s; }
    void setMemoryAmt(int m){ memoryAmt = m; }
    void setCounterNum(int n){ counterNum = n; }

    // Methods
    static void printCurrentStep();
    static void printStartDisplay();
    static void printEndDisplay();

    // No getters because why

};
