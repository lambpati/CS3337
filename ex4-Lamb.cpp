// Name: Patience Lamb
// Brief: Does the entirety of HW4 coding in one source file
// Out of good design when using multiple packages and namespaces, std is not
// used as the default namespace.
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

//TODO: Finish up findOccurances and the commnents, do 5, 6, 7, 8

bool findOccurances(int mat[3][5], int col, int b){
   for(int i = 0; i < col; i++){
    if(*std::find(std::begin(mat[i]),std::end(mat[i]), b) != b) return false;
  }
  return true;
}


// Iterates to the right to find the first value of a maximum's index
int findMaxima(int (&a)[], int n){
  int maximumIndex = 0;
  for(int i = 0; i < n; i++){
    if(a[i] > a[maximumIndex]) maximumIndex = i;
  }
  return maximumIndex;
}


// Iterates to the right to find the first value of a minimum's index
int findMinima(int (&a)[], int n){
  int minimumIndex = 0;
  for(int i = 0; i < n; i++){
    if(a[i] < a[minimumIndex]) minimumIndex = i;
  }
  return minimumIndex;
}

template<size_t a_size>
// Reverses the array given an array of size_t and the std::reverse and iterators
void reverseArray(int (&a)[a_size]){
  std::reverse(std::begin(*&a), std::end(*&a));
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
  std::cout << findOccurances(b1, 3, 91);
  std::cout << findOccurances(b2, 3, 91);

  return 0;
}
