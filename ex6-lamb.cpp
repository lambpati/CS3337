// Name: Patience Lamb
// Brief: Does the entirety of HW6 coding in one source file
// Out of good design when using multiple packages and namespaces, std is not
// used as the default namespace.
#include <iostream>
#include <fstream>
#include <string>

// Writes to file one character at a time using put
void writeChar(std::ofstream &file){
  std::string str = "Line one \nLine two \nLine \nthree";
  for(auto &c : str) file.put(c);
  file.close();
}

// Reads file using get, fail, and eof, throws exception if fails
std::string readFile(std::ifstream &file){
  std::string str;
  if(file.fail()){
    throw std::ifstream::failure("Failed to open  (pt 2) output.txt");
  }
  while(!file.eof()){
    str += file.get();
  }
  file.close();
  return str;
}

// input method code using fail and eof
std::string inputMethod(std::ifstream &file){
  std::string str1, str2 = "";
  if(file.fail()){
    throw std::ifstream::failure("Failed to open (pt 3) output.txt");
  }
  while(!file.eof()){
      file >> str2;
      str1 += str2;
  }
  file.close();
  return str1;
}

// Code to test writeUnLongLongToBinary from note 6.1
unsigned long long* readUsLongLongFromBinary(const std::string &fileName, const std::string &binaryName) {
long size;
// first determine how much stuff to read – create array of appropriate size
std::ifstream cbf(fileName, std::ios::binary | std::ios::in);
cbf.seekg(0, std::ios::end);       // seek is a very old command - goes back to reading 1600bpi tapes
size = cbf.tellg();
cbf.seekg(0, std::ios::beg);
cbf.close();
std::ifstream binaryIo1;
unsigned long long *y = new unsigned long long[size/sizeof(unsigned long long)];
binaryIo1.open(binaryName, std::ios::in | std::ios::binary);
binaryIo1.seekg(0);
binaryIo1.read((char*)y, size);
binaryIo1.close();
return y;   //returns pointer to unsigned long long array
}

// Writes to a binary file the contents of a unsigned long long array.
void writeUnLongLongToBinary(unsigned long long *y, long ysize, std::string filename){
  std::ofstream file(filename, std::ios::out | std::ios::binary | std::ios::trunc);
  file.seekp(0);
  file.write((char*)y, ysize*sizeof(y[0]));
  file.close();

}

// Read amd move ascii to bin file, returns str size
long moveASCII(const std::string &txtFile, const  std::string &binFile){
  std::ifstream textFile(txtFile);
  std::string str = readFile(textFile);

  unsigned long long *x = new unsigned long long[str.size()];
  for(int i = 0; i < str.size(); i++){
    x[i] = (unsigned long long)str.at(i);
  }

  std::cout << "The string is " << str.size() << " ASCII characters long." << std::endl;
  writeUnLongLongToBinary(x, str.size(), binFile);

  return str.size();
}

// reads the ASCII, converts it to a unsigned long long and then to a string output
void readASCII(const std::string &txtFile, const std::string &binFile, long size){
  unsigned long long *y;
  std::string str = "";

  y = readUsLongLongFromBinary(binFile, binFile);
  for(int i = 0; i < size; i++){
    str += y[i];
  }
  std::ofstream output(txtFile);
  output << str;
  output.close();
}


int main(int argc, char const *argv[]) {
  // writeChar output
  std::ofstream output("output.txt");
  writeChar(output);

    try{
    // readFile inputs
    std::ifstream input("output.txt");
    std::cout << readFile(input) << std::endl;
    std::cout << "End of pt 2." << std::endl;

    // inputMethod inputs
    std::ifstream input1("output.txt");
    std::cout << inputMethod(input1) << std::endl;
    std::cout << "End of pt 3." << std::endl;
  }
  catch(std::ifstream::failure &e){
    std::cerr << e.what() << std::endl;
  }

  // writeUnLongLongToBinary inputs array of 1 to 100
  unsigned long long *x = new unsigned long long[100];
  std::cout << "Here is the original input: " << std::endl;
  for(int i = 0; i < 100; i++) x[i] = i+1;
  for (int i = 0; i < 100; i++) std::cout << x[i] << " ";
  std::cout << std::endl << std::endl;

  writeUnLongLongToBinary(x,100,"pt4.bin");

  // readUsLongLongFromBinary from note 6.1
  unsigned long long *y;
  y = readUsLongLongFromBinary("pt4.bin", "pt4.bin");
  std::cout << "Here is the output: " << std::endl;
  for (int i = 0; i<100; i++) std::cout << y[i] << " ";

  delete x;
  delete y;
  std::cout << "End of pt 4." << std::endl;

  // moveASCII
  try{
  std::string txtFile;
  long strSize;
  std::cout << "Please specify file to convert (including extension & relative path)" << std::endl;
  std::cin >> txtFile;
  strSize = moveASCII(txtFile, "persuasion.bin");
  std::cout << "The binary file is stored as persuasion.bin" << std::endl;

  // readASCII
  readASCII("persuasion_out.txt", "persuasion.bin", strSize);
  std::cout << "The text file is stored as persuasion_out.txt" << std::endl;
}
catch(std::ifstream::failure &e){
  std::cerr << e.what() << std::endl;
}

  return 0;
}
