#include "ReadProgram.hh"
#include "UserControl.hh"

ReadProgram::ReadProgram(){
   file.exceptions(std::ifstream::badbit); //I dont see why to check for badbits
   try{
       // File read and write
       file.open(UserControl::getFileName());
       if(!file.is_open()){
       throw std::ifstream::failure("Cannot find file");
       }
       std::getline(file,str);
       // Assuming first line is always the amount of lines to execute
       lineAmt = std::stoi(str);

   }
   catch(const std::ifstream::failure& e){
       std::cerr << e.what() << std::endl;
   }
}
