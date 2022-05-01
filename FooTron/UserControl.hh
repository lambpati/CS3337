#pragma once
#include <string>

class UserControl{
  private:
    static std::string fileName;
    static bool uNext;
    static bool uRestart;
    static bool uStop;

  public:
    UserControl() = default;

    // Setters
    static void setFileName(std::string f){ fileName = f; } 
    void setNext(bool c){ uNext = c; }
    void setRestart(bool r){ uRestart = r; }

    // Getters
    static std::string getFileName() { return fileName; }
    static int getNext() { return uNext; }
    static int getRestart(){ return uRestart; }
    static int getStop(){ return uStop; }

    // Methods
    static void DetermineControl();

};
