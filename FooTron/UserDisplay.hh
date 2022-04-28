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
    int lineNum;

  public:
    UserDisplay(int, int, std::string, std::string, int, int, int);
    UserDisplay();

    // Setters
    void setCurrentAddr(int a){ currentAddr = a; }
    void setNextAddr(int a){ nextAddr = a; }
    void setCurrentIns(std::string s){ currentIns = s; }
    void setNextIns(std::string s){ nextIns = s; }
    void setMemoryAmt(int m){ memoryAmt = m; }
    void setCounterNum(int n){ counterNum = n; }
    void setLineNum(int n){ lineNum = n; }

    // Methods
    void printCurrentStep();
    static void printStartDisplay();
    static void printEndDisplay();

    // No getters because why

};
