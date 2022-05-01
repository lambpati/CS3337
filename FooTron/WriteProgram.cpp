#include "WriteProgram.hh"
#include "UserControl.hh"

std::string WriteProgram::output = "output.txt";
std::ofstream WriteProgram::out;

// Results stored in build folder "output.txt"
void WriteProgram::writeToOutput(std::vector<int> val){
  out.open(output, std::ios_base::trunc);
    for(auto &e : val){
      out << e;
      out << '\n';
    }
}
