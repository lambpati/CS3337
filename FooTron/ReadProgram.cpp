// Name: Patience Lamb
// Gets contents of a file and puts it in memory

#include "ReadProgram.hh"
#include "Memory.hh"
#include "UserControl.hh"
#include <iostream>
#include <string>

std::ifstream ReadProgram::file;
int ReadProgram::lineNum;
std::string ReadProgram::contents;

// Reads contents of a file specified by user then puts it into the memory vector
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
       lineNum++;
     }
   }
   catch(const std::ifstream::failure& e){
       std::cerr << e.what() << std::endl;
   }
}
