#pragma once
#include <fstream>
#include <string>

class ReadProgram{
  private:
    std::ifstream file;
    static int lineAmt;
    int lineNum;
    static std::string contents;
  public:
    ReadProgram();

    // Getters
    int getLineAmt const (){ return lineAmt; }
    int getLineNum const () { return lineNum; }

    // Methods
    std::string readNextLine();


};
