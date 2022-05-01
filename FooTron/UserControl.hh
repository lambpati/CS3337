#pragma once
#include <string>

class UserControl{
  private:
    static std::string fileName;
    static bool next;
    static bool restart;

  public:
    UserControl() = default;

    // Setters
    static void setFileName(std::string f){ fileName = f; }
    void setNext(bool c){ next = c; }
    void setRestart(bool r){ restart = r; }

    // Getters
    static std::string getFileName() { return fileName; }
    int getNext() const{ return next; }

    // Methods

};
