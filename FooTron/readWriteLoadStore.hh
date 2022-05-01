#pragma once

#include <vector>

class readWriteLoadStore{
  private:
    int addr;
    static int value;
    static std::vector<int> writtenValues;

  public:
    readWriteLoadStore() = default;

    //Methods
    static void read(int a);
    static void write(int a);
    static void load(int a);
    static void store(int a);

    // getters
    static std::vector<int> getWrittenValues(){
      return writtenValues;
    }
};
