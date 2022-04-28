#pragma once
#include <fstream>

class ReadProgram{
  private:
    std::ifstream file;
    int lineAmt;
  public:
    ReadProgram();

    // Getters
    int getLineAmt const (){ return lineAmt; }

};
