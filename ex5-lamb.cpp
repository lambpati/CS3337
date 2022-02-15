// Name: Patience Lamb
// Brief: Does the entirety of HW5 coding in one source file
// Out of good design when using multiple packages and namespaces, std is not
// used as the default namespace.

#include <iostream>
#include <string>

template<size_t a_size>
// Sums an array of unsigned ints using pointer arithmetic.
unsigned sumInts(unsigned (&a)[a_size]){
  unsigned sum;
  unsigned *ptr1;
  ptr1 = a;
  const unsigned end = a[a_size];
  while(*ptr1 != end){
    sum += *ptr1;
    ptr1++;
  }
  return sum;
}

// Sums ASCII using a string with 10 letters and pointers.
unsigned long long *sumASCII(const std::string &s){
  static unsigned long long arr[10];
  int sum = 0;
  for(int i = 0; i < 10; i++){
    int c = static_cast<int>(s.at(i));
    sum += c;
    arr[i] = sum;
  }
  return arr;
}

// Counts the number of times count2 is called using global int.
int count2_calls = 0;
void count2(){
   count2_calls++;
}

// Counts the number of times count1 is called using static int.
int count1(){
  static int num_called = 0;
  num_called++;
  return num_called;
}

int main(int argc, char const *argv[]) {
  // count1 tests
  std::cout << "count1 should be called 5 times." << std::endl;
  for(int i = 0; i < 5; i++){
    std::cout << "Number of times count1 is called: " << count1() << std::endl;
  }

  // count2 tests
  std::cout << "count2 should be called 5 times." << std::endl;
  for(int i = 0; i < 5; i++){
    count2();
    std::cout << "Number of times count2 is called: " << count2_calls << std::endl;
  }

  // sumASCII tests
  std::string str = "fhmLtnFVLq";
  std::cout << "The string " << str << " has the summed array of:" << std::endl;
  unsigned long long* a;
  a = sumASCII(str);
  for(int i = 0; i < str.size(); i++){
    std::cout << a[i] << ",";
  }
  std::cout << "\n";

  // sumInts tests
  unsigned s;
  unsigned arr[] = {91,9,69,14,6};
  std::cout << "The sum of ";
  for(auto &i : arr){
    std::cout << i << ",";
  }
  std::cout << " is " << sumInts(arr) << std::endl;



  return 0;
}
