// Name: Patience Lamb
// Brief: Does the entirety of HW3 coding in one source file
// Out of good design when using multiple packages and namespaces, std is not
// used as the default namespace.
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <regex>
#include <limits>


// Counts the number of occurances of character c in s using count iterator.
int countChar(char c, const std::string &s){
    return std::count(s.begin(), s.end(), c);
}

// Reverses the string using a temporary intermediate string and the reverse iterator.
std::string reverse(const std::string &s){
  std::string intermediate = s;
  std::reverse(intermediate.begin(), intermediate.end());
  return intermediate;
}


// Sums the ascii values of the string s using a static cast in a for loop.
int sumASCII(const std::string &s){
  int sum;
  for(auto &ch: s){
    int c = static_cast<int>(ch);
    sum += c;
  }
  return sum;
}

// Parses hexidecimal using the power of 10 to power of 16 conversion and
// Accounting for ASCII conversions. NOTE: FD = 253 not 254.
unsigned long parceHex(const std::string &hexString){
  unsigned long answer = 0;
  for(int i = 0; i < hexString.length(); i++){
    int base = pow(16,hexString.length()-i-1);
    if(hexString[i] >= 48 && hexString[i] <= 57){
      answer += (hexString[i]-48)*base;
    }
    else if(hexString[i] >= 65 && hexString[i] <= 102){
      answer += (hexString[i]-55)*base;
    }
    else if(hexString[i]>=97 && hexString[i]<=102){
      answer += (hexString[i]-87)*base;
    }
  }

  return answer;
}

// Uses regex to convert two or more consecutive spaces to one space
std::string replaceSpaces(const std::string &s){
  std::string str;
  str = std::regex_replace(s, std::regex("[' ']{2,}"), " ");
  return str;
}

// Converts character to integer and adds 128, does mod 256, and then returns
// the resulting character.
char ROT128Char(const char &c){
  return (static_cast<int>(c) + 128) % 256;
}

// Undoes ROT128 assuming original characters are between 0 and 127.
char undoROT128(const char &c){
  return static_cast<char>(static_cast<int>(c)-128);
}

// Uses ROT128 algorithm above to apply across a string.
std::string stringROT128(const std::string &s){
  std::string str;
  for(auto ch : s) str += ROT128Char(ch);
  return str;
}
// Undoes ROT128 string algorithm using the undoROT128 algorithm above.
std::string undoStringROT128(const std::string &s){
  std::string str;
  for(auto ch : s) str += undoROT128(ch);
  return str;
}


int main(int argc, char const *argv[]) {
  // countChar inputs and outputs
  std::string sIn;
  char cIn;
  std::cout << "Enter string for countChar: ";
  std::getline(std::cin, sIn);
  std::cout << "Enter character to search for: ";
  std::cin >> cIn;

  std::cout << "The amount of times " << cIn << " occurs in " << sIn << " is "
            << countChar(cIn, sIn) << std::endl;

  // cin overflow flush to use getline
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  // reverse inputs and outputs
  std::string sReverse;
  std::cout << "Enter string for reverse: ";
  std::getline(std::cin, sReverse);

  std::cout << sReverse << " reversed is " << reverse(sReverse) << std::endl;

  // sumASCII inputs and outputs
  std::string sASCII;
  std::cout << "Enter string for ASCII summing: ";
  std::getline(std::cin, sASCII);

  std::cout << sASCII << " summed is " << sumASCII(sASCII) << std::endl;

  // parceHex inputs and outputs
  std::string hex;
  std::cout << "Enter hexstring for decimal conversion: ";
  std::getline(std::cin, hex);

  std::cout << hex << " summed is " << parceHex(hex) << std::endl;

  // replaceSpaces inputs and outputs
  std::string spaceString;
  std::cout << "Enter string with multiple spaces for conversion: " << std::endl;
  std::getline(std::cin, spaceString);

  std::cout << "|" << spaceString << "|" << " is " << "|" << replaceSpaces(spaceString)
            << "|" << " single spaced." << std::endl;

  // ROT128 inputs and outputs
  char ch;
  std::cout << "Enter a character for ROT128: ";
  std::cin >> ch;

  std::cout << ch << " with ROT128 is " << ROT128Char(ch) << std::endl;

  // Allow user to use another character to decrypt
  char decision;
  std::cout << "Would you like to enter a unique character to reverse ROT128? [y/N]";
  std::cin >> decision;

  if(decision == 'y'){
    char cROT;
    std::cout << "Enter a character in ROT128: ";
    std::cin >> cROT;

    std::cout << cROT << " undone is " << undoROT128(cROT) << std::endl;
  }
  else{
    std::cout << ROT128Char(ch) << " undone is " << undoROT128(ROT128Char(ch))
              << std::endl;
  }

  // cin overflow flush to use getline
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  // ROT128 string inputs and outputs
  std::string strROT;
  std::cout << "Enter a string for ROT128: ";
  std::getline(std::cin, strROT);

  std::cout << strROT << " with ROT128 is " << stringROT128(strROT) << std::endl;

  // Allow user to use another string to decrypt
  char decisionS;
  std::cout << "Would you like to enter a unique string to reverse ROT128? [y/N]";
  std::cin >> decisionS;

  if(decisionS == 'y'){
    std::string sROT;
    std::cout << "Enter a string in ROT128: ";

    // cin overflow flush to use getline
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::getline(std::cin, sROT);

    std::cout << sROT << " undone is " << undoStringROT128(sROT) << std::endl;
  }
  else{
    std::cout << stringROT128(strROT) << " undone is " <<
                undoStringROT128(stringROT128(strROT)) << std::endl;
  }

  return 0;
}
