#pragma once

class Arithmetic{
  private:
    static int value;
  public:
    Arithmetic() = default;

    //methods
    static void add(int a);
    static void subtract(int a);
    static void divide(int a);
    static void multiply(int a);
};
