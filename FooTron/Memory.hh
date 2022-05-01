#pragma once
#include <vector>


class Memory{
  public:
    static std::vector<int> memory;

    Memory() = default;

    // Setters
    static void setMemory(int a, int value){
      memory.at(a) = value;
    }

    // Getters
    static int getMemory(int a){
      return memory.at(a);
    }

};
