// Parses out the instructions from the contents as well as the location
#pragma once

class Accumulator{
  private:
    static int location;
  public:
    Accumulator() = default;

    // Getters
    static int getLocation(){ return location; }

    // Setters
    static void setLocation(int l){location = l;}
};
