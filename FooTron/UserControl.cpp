#include "UserControl.hh"
#include <iostream>

std::string UserControl::fileName = "";
bool UserControl::uNext = 0;
bool UserControl::uRestart = 0;
bool UserControl::uStop = 0;

void UserControl::DetermineControl(){
  uNext = 0;
  uRestart = 0;
  uStop = 0;

  std::string keyboardAction = "";
  std::cin >> keyboardAction;

  if(keyboardAction == "n" || keyboardAction == "N"){
    uNext = 1;
    return;
  }
  else if(keyboardAction == "x" || keyboardAction == "X"){
    uStop = 1;
    exit(0);
  }
  else if(keyboardAction == "r" || keyboardAction == "R"){
    uRestart = 1;
  }
}
