#pragma once
#include <string>

class UserControl{
  private:
    std::string fileName;
    bool next;
    bool restart;

  public:
    UserControl(std::string, bool, bool);
    UserControl();

    // Setters
    void setFileName(std::string f){ fileName = f; }
    void setNext(bool c){ next = c; }
    void setRestart(bool r){ restart = r; }

    // Getters
    std::string getFileName const(){ return fileName; }
    int getNext const(){ return next; }

    // Methods


}
