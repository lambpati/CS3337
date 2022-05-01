#include "ReadProgram.hh"
#include "Memory.hh"
#include "UserControl.hh"
#include <iostream>
#include <string>

std::ifstream ReadProgram::file;
int ReadProgram::lineNum;
std::string ReadProgram::contents;

void ReadProgram::read(){
  lineNum = 0;
   file.exceptions(std::ifstream::badbit); //I dont see why to check for badbits
   try{
       // File read and write
       file.open(UserControl::getFileName());
       if(!file.is_open()){
       throw std::ifstream::failure("Cannot find file");
     }
     std::string tp;
     int values;
     while(getline(file, tp)){
       values = std::stoi(tp);
      Memory::setMemory(lineNum, values);
      // std::cout << Memory::memory.at(lineNum);
       lineNum++;
     }
   }
   catch(const std::ifstream::failure& e){
       std::cerr << e.what() << std::endl;
   }
}
