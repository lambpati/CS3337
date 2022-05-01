#pragma once

class readWriteLoadStore{
  private:
    int addr;
    static int value;

  public:
    readWriteLoadStore() = default;

    //Methods
    static void read(int a);
    static void write(int a);
    static void load(int a);
    static void store(int a);
};
