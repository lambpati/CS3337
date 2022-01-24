// Name: Patience Lamb
// Brief: Accepts two integers and returns the sum of the integers
#include <iostream>

// Uses modulus 4 to determine if the year was a leap year
bool isLeapYear(unsigned int year){
  if(year%4==0){
    return true;
  }
  return false;
}

// Sums the values between n1 and n2 inclusive
int sumIntegers(int n1, int n2){
  int sum = 0;
  if(n2 > n1){
    for(int i=n1; i <= n2; i++){
      sum += i;
    }
  }
  if (n1 > n2){
    for(int i=n2; i <= n1; i++){
      sum += i;
    }
  }
  return sum;
}

int main(int argc, char const *argv[]) {
  int n1, n2;
  // Grab user input of n1 and n2
  std::cout << "Enter n1 value: " << std::endl;
  std::cin >> n1;
  std::cout << "Enter n2 value: " << std::endl;
  std::cin >> n2;

  // Print sum of n1 and n2 inclusive
  std::cout << "Sum of integers between n1 and n2 inclusive: "<< sumIntegers(n1,n2) << std::endl;

  unsigned int year;
  // Grab user input of isLeapYear
  std::cout << "Enter value of year: " << std::endl;
  std::cin >> year;

  //Print if year is a leap year
  std::cout << "Is " << year << " a leap year? " << isLeapYear(year);
  return 0;
}
