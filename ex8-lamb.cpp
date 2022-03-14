// Name: Patience Lamb
// Brief: Does the entirety of HW8 coding in one source file
#include <iostream>
#include <bitset>

using namespace std;

// Creates an unsigned 16bit short packed1 which adds the values of c1-c4 together and shifts the bits left 4 each time.
// Messy but could be cleaned up by adding characters to an array or something. For simplicity and proof of concept, is just 4 individual things and repeating code.
unsigned short pack1(char c1, char c2, char c3, char c4){
    unsigned short packed1;
    packed1=c1;
    packed1=packed1<<4;
    bitset<16> bitset1(packed1);
    cout << "packed1 bitset after shift w/ c1: " << bitset1 << endl;
    packed1=packed1|c2;
    packed1=packed1<<4;
    bitset<16> bitset2(packed1);
    cout << "packed1 bitset after shift w/ c2: " << bitset2 << endl;
    packed1=packed1|c3;
    packed1=packed1<<4;
    bitset<16> bitset3(packed1);
    cout << "packed1 bitset after shift w/ c3: " << bitset3 << endl;
    packed1=packed1|c4;
    return packed1;
}

// Unpacks value from pack1 using binary shifts right and AND'ing the highest significant digit in the shifted value.
void unpack1(unsigned short packed1, char &c5, char &c6, char &c7, char &c8){
    c5 = (packed1 & 0xF000) >> 12; //Returns c1 after shifting 4*3 times
    c6 = (packed1 & 0xF00) >> 8;  //Returns c2 after shifting 4*2 times
    c7 = (packed1 & 0x00F0) >> 4; //Returns c3 after shifting 4 times
    c8 = packed1 & 0x000F; //Returns c4
}

// Packs integer characters into an unsigned 32 bit integer by shifting left 8 bits and OR'ing values together.
uint32_t packCharsIntoInt(char c1, char c2, char c3, char c4) {  
	return (((((c1 << 8)|c2) << 8)|c3) << 8)|c4;
} 

// Unpacks characters from an unsigned 32 bit integer by unpacking the value using binary shifts right and AND'ing the highest significant digit in the shifted value.
void unpackCharsFromInt(uint32_t packed2, char &c13, char &c14, char &c15, char &c16){
    c13 = (packed2 & 0xFF000000) >> 24; // Returns c9 after shifting 8*3 times
    c14 = (packed2 & 0x00FF0000) >> 16; // Returns c10 after shifting 8*2 times
    c15 = (packed2 & 0x0000FF00) >> 8; // Returns c11 after shifting 8 times
    c16 = (packed2 & 0x00000000FF); // Returns c12
}

int main(int argc, char const *argv[]) {
    // Q1 inputs/ outputs
    // Setting c1, c2, c3, c4 to 3, 5, 7, 9
    char c1 = 3; char c2 = 5; char c3 = 7; char c4 = 9;
    bitset<16> bitset4(c1); bitset<16> bitset5(c2); bitset<16> bitset6(c3); bitset<16> bitset7(c4);
    unsigned short packed1 = pack1(c1,c2,c3,c4);
    bitset<16> bitset8(packed1);
    cout << "c1 bitset originally: " << bitset4 << endl;
    cout << "c2 bitset originally: " << bitset5 << endl;
    cout << "c3 bitset originally: " << bitset6 << endl;
    cout << "c4 bitset originally: " << bitset7 << endl;
    cout << "packed1 final value: " << bitset8 << endl;

    cout << endl;

    // Q2 inputs/outputs 
    char c5, c6, c7, c8;
    unpack1(packed1, c5, c6, c7, c8);
    cout << " c5: " << (int) c5 << endl;
    cout << " c6: " << (int) c6 << endl;
    cout << " c7: " << (int) c7 << endl;
    cout << " c8: " << (int) c8 << endl;

    cout << endl;

    // Q3 inputs/outputs
    char c9 = 'A'; char c10 = 'X'; char c11 = 'M'; char c12 = 'D';
    bitset<16> bitset9(c9); bitset<16> bitset10(c10); bitset<16> bitset11(c11); bitset<16> bitset12(c12);
    cout << "c9 bitset originally: " << bitset9 << endl;
    cout << "c10 bitset originally: " << bitset10 << endl;
    cout << "c11 bitset originally: " << bitset11 << endl;
    cout << "c12 bitset originally: " << bitset12 << endl;
    uint32_t packed2 = packCharsIntoInt(c9,c10,c11,c12);
    bitset<32> bitset13(packed2);
    cout << "packCharsIntoInt: " << bitset13 << endl;

    cout << endl;

    // Q4 inputs/outputs
    char c13, c14, c15, c16;
    unpackCharsFromInt(packed2, c13, c14, c15, c16);
    cout << " c13: " << (char) c13 << endl;
    cout << " c14: " << (char) c14 << endl;
    cout << " c15: " << (char) c15 << endl;
    cout << " c16: " << (char) c16 << endl;




    
}
