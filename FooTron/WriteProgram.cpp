// Name: Patience Lamb
// Writes an array of values into a txt file

#include "WriteProgram.hh"
#include "UserControl.hh"

std::string WriteProgram::output = "output.txt";
std::ofstream WriteProgram::out;

// Writes array values val into a txt file known as "output.txt"
void WriteProgram::writeToOutput(std::vector<int> val){
  // Results stored in build folder "output.txt"
  out.open(output, std::ios_base::trunc);
    for(auto &e : val){
      out << e;
      out << '\n';
    }
}
