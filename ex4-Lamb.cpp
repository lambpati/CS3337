// Name: Patience Lamb
// Brief: Does the entirety of HW4 coding in one source file
// Out of good design when using multiple packages and namespaces, std is not
// used as the default namespace.
#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>
#include <string>
#include <math.h>
#include <algorithm>

template<size_t a_size>
// Reverses the array given an array of size_t and the std::reverse and iterators
void reverseArray(int (&a)[a_size]){
  std::reverse(std::begin(*&a), std::end(*&a));
}

// Iterates to the right to find the first value of a minimum's index
int findMinima(int (&a)[], int n){
  int minimumIndex = 0;
  for(int i = 0; i < n; i++){
    if(a[i] < a[minimumIndex]) minimumIndex = i;
  }
  return minimumIndex;
}

// Iterates to the right to find the first value of a maximum's index
int findMaxima(int (&a)[], int n){
  int maximumIndex = 0;
  for(int i = 0; i < n; i++){
    if(a[i] > a[maximumIndex]) maximumIndex = i;
  }
  return maximumIndex;
}

// Given a 3x5 matrix, find if each row contains b by iterating through the
// columns and using find in each row
bool findOccurances(int mat[3][5], int col, int b){
   for(int i = 0; i < col; i++){
    if(*std::find(std::begin(mat[i]),std::end(mat[i]), b) != b) return false;
  }
  return true;
}

template<size_t a_size>
// Finds the amount of times b occurs in array a using std::count and iterators
int frequencyCount(int (&a)[a_size], int b){
  return std::count(std::begin(*&a), std::end(*&a), b);
}

template<size_t a_size>
// Finds the mean of an array using std::accumulate and iterators, dividing it by
// the length of a
int findMean(int (&a)[a_size]){
  return std::accumulate(std::begin(*&a), std::end(*&a), 0)
          / (sizeof(a)/sizeof(a[0]));
}

// Returns an unsigned integer array's pointer of the counts of numerical values
// kept in the string of integers 0-9 using a ranged-for loop and std::count.
unsigned int *numeralFreqCount(const std::string &s){
  unsigned int* counter = new unsigned int[10];
  unsigned int i = 0;
  for(const char target : {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}){
      const int n = std::count(s.cbegin(), s.cend(), target);
      counter[i] = n;
      i++;
  }
  return counter;
}


template<size_t a_size>
// Uses findMean to calculate the variance and then the standard deviation
int calculateStdDev(int (&a)[a_size]){
  int mean = findMean(a);
  int variance = 0;
  int stddev;
  for(auto &it: a){
    variance += pow((it-mean),2);
  }
  variance /= (sizeof(a)/sizeof(a[0]));
  stddev = sqrt(variance);
  return stddev;
}

int main(int argc, char const *argv[]) {
  // Outputs for reverseArray.
  // The user has to enter a vector of size 5.
  int array1[5];
  std::cout << "Enter an array to be reversed" << std::endl;
  for(int i = 0; i < 5; i++){
    std::cout << "Enter value at index " << i << std::endl;
    std::cin >> array1[i];
  }
  reverseArray(array1);
  std::cout << "Here's the reversed array: ";
  for(auto e : array1){
    std::cout << e << ",";
  }
  std::cout << '\n';

  // Outputs for findMinima
  // The user has to enter a vector of size 5.
  int array2[5];
  std::cout << "Enter an array to find minima" << std::endl;
  for(int i = 0; i < 5; i++){
    std::cout << "Enter value at index " << i << std::endl;
    std::cin >> array2[i];
  }
  std::cout << "The index for the minimum value for the array is "
            << findMinima(array2, sizeof(array2)/sizeof(array2[0]))
            << std::endl;

  // Outputs for findMaxima
  // The user has to enter a vector of size 5.
  int array3[5];
  std::cout << "Enter an array to find maxima" << std::endl;
  for(int i = 0; i < 5; i++){
    std::cout << "Enter value at index " << i << std::endl;
    std::cin >> array3[i];
  }
  std::cout << "The index for the maximum value for the array is "
            << findMaxima(array3, sizeof(array3)/sizeof(array3[0]))
            << std::endl;

  // Outputs for findOccurances
  // To save time so it is not necessary to enter a 3,5 matrix, two matricies is
  // below and b = 91
  int b1[3][5] = {
                  {91,9,69,14,6},
                  {15,65,11,12,1},
                  {38,58,60,2,73}
                  };
  int b2[3][5] {
                {91,9,69,14,6},
                {15,65,91,12,1},
                {38,58,60,2,91}
              };
  std::cout << "Does matrix b1 contain a 91 in each row? " << findOccurances(b1, 3, 91)
            << std::endl;
  std::cout << "Does matrix b2 contain a 91 in each row? " << findOccurances(b2, 3, 91)
            << std::endl;

    // Outputs for frequencyCount
    // The user has to enter a vector of size 5 and a value to look for.
    int array4[5];
    int b;
    std::cout << "Enter an array:" << std::endl;
    for(int i = 0; i < 5; i++){
        std::cout << "Enter value at index " << i << std::endl;
        std::cin >> array4[i];
      }
    std::cout << "Enter value to search for in array: ";
    std::cin >> b;
    std::cout << "The amount of times " << b << " occurs is "
              << frequencyCount(array4,b)
              << std::endl;

  // Outputs for findMean
  // Smalll array of random numbers to try it out on
  int smallArray[5];
  std::cout << "Random array of 5 integers is: ";
  for(auto &e : smallArray){
    e = rand()%1000;
    std::cout << e << ",";
  }
  std::cout << '\n';
  std::cout << "The mean of the array is " << findMean(smallArray) << std::endl;

  // Large array of random numbers to try it out on
  int largeArray[100];
  std::cout << "Random array of 100 integers is: " << std::endl;
  for(auto &e : largeArray){
    e = rand()%1000;
    std::cout << e << ",";
  }
  std::cout << '\n';
  std::cout << "The mean of the array is " << findMean(largeArray) <<std::endl;

  // Outputs for numeralFreqCount
  std::string s; //= "0033344AA667";
  std::cout << "Enter string to test the numeralFreqCount on: ";
  std::cin >> s;
  std::cout << "The array of the numerical values is: ";
  unsigned int* array6 = numeralFreqCount(s);
  for(int i = 0; i < 10; i++){
    std::cout << array6[i] << ",";
  }
  delete[] array6;
  std::cout << '\n';

  // Outputs for calculateStdDev
  // The user has to enter a vector of size 5 and a value to look for.
  int array7[5];
  std::cout << "Enter an array:" << std::endl;
  for(int i = 0; i < 5; i++){
      std::cout << "Enter value at index " << i << std::endl;
      std::cin >> array7[i];
    }
    std::cout << "The standard deviation of the array is: "
              << calculateStdDev(array7)
              << std::endl;




  return 0;
}
