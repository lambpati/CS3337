// Name: Patience Lamb
// Brief: Does the entirety of HW2 coding in one source file
// Out of good design when using multiple packages and namespaces, std is not
// used as the default namespace.
#include <iostream>


// Sums the digits of n recursively by taking adding the modulus of n to the sum
// and de-incrementing by n / 10
int sumDigits(int n, int sum = 0){
  if (n < 0) return -1;
  if(n == 0) return sum;
  sum = sum + n % 10;
  n = n / 10;
  return sumDigits(n, sum);
}

// Converts integer into character according to the ASCII table
char getCharFromAsciiValue (int n) {
  return (static_cast<char> (n));
}

// Creates a string of n length using '-', prints it out and then iterates
// through the string starting from the end replacing the last non-"*" value.
void dashesToStars(int n){
  std::string seqChar = std::string(n, '-');
  std::string stars = "*";
  std::cout << seqChar << std::endl;
  while(n != 0){
    seqChar.replace(n-1,1,stars);
    std::cout << seqChar << std::endl;
    n = n-1;
  }

}

// Uses modulus 4, 100, and 400 to determine if the year was a leap year
bool isLeapYear(unsigned int year){
  if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0) return true;
  return false;
}

// Sums the values between n1 and n2 inclusive
int sumIntegers(int n1, int n2){
  int sum = 0;
  if(n2 > n1){
    for(int i = n1; i <= n2; i++){
      sum += i;
    }
  }
  if (n1 > n2){
    for(int i = n2; i <= n1; i++){
      sum += i;
    }
  }
  return sum;
}

int main(int argc, char const *argv[]) {
  // Grab user input of n1 and n2
  int n1, n2;
  std::cout << "Enter n1 value: " << std::endl;
  std::cin >> n1;
  std::cout << "Enter n2 value: " << std::endl;
  std::cin >> n2;

  // Print sum of n1 and n2 inclusive
  std::cout << "Sum of integers between n1 and n2 inclusive: "<< sumIntegers(n1,n2) << std::endl;

  // Grab user input of isLeapYear
  unsigned int year;
  std::cout << "Enter value of year: " << std::endl;
  std::cin >> year;

  //Print if year is a leap year
  std::cout << "Is " << year << " a leap year? " << isLeapYear(year) << std::endl;

  // Grabs user input of dashesToStars
  int n;
  std::cout << "Enter a value for n (dashesToStars): " << std::endl;
  std::cin >>  n;

  // Executes dashesToStars
  dashesToStars(n);

  // Grabs user input of getCharFromAsciiValue
  int na;
  std::cout << "Enter a value for n (getCharFromAsciiValue): " << std::endl;
  std::cin >> na;

  // Prints out the values casted from getCharFromAsciiValue
  std::cout << "Character corresponding to " << na << " is " << getCharFromAsciiValue(na) << std::endl;

  // Grabs user input of sumDigits
  int nb;
  std::cout << "Enter a value for n (sumDigits): " << std::endl;
  std::cin >>  nb;

  // Prints out the values casted from sumDigits
  std::cout << "The sum of " << nb << " is " << sumDigits(nb) << std::endl;

  return 0;
}
