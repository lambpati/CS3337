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
    static getFileName const(){ return fileName; }

    // Methods


}
