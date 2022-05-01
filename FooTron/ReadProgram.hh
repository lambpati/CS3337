#pragma once
#include <fstream>
#include <string>

class ReadProgram{
  private:
    static std::ifstream file;
    static int lineNum;
    static std::string contents;
  public:
    ReadProgram() = default;

    // Getters
    static int getLineNum() { return lineNum; }

    //Methods
    static void read();
};
