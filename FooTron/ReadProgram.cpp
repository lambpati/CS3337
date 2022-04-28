#include "ReadProgram.hh"
#include "UserControl.hh"

ReadProgram::ReadProgram(){
  lineNum = 1;
   file.exceptions(std::ifstream::badbit); //I dont see why to check for badbits
   try{
       // File read and write
       file.open(UserControl::getFileName());
       if(!file.is_open()){
       throw std::ifstream::failure("Cannot find file");
       }
       std::getline(file,contents);
       // Assuming first line is always the amount of lines to execute
       lineAmt = std::stoi(contents);

   }
   catch(const std::ifstream::failure& e){
       std::cerr << e.what() << std::endl;
   }
}

ReadProgram::readNextLine(){
  if(!file.eof() && UserControl::getNext()){
    std::getline(file, contents);
    lineNum++;
    return contents;
  }
}
