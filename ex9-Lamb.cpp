// Name: Patience Lamb
// Brief: Does the entirety of HW9 coding in one source file
#include <iostream>
#include <ctime>
#include <math.h>
#include <random>

using namespace std;

const unsigned long long size100 = 100;
const unsigned long long size1000 = 1000;
const unsigned long long size10000 = 10000;

// Creates a random number using bitwise arithmetic on memory addresses.
unsigned int randFoo() {
	static unsigned int z1 = 12345, z2 = 12345, z3 = 12345, z4 = 12345;
	unsigned int b;
	b = ((z1 << 6) ^ z1) >> 13;
	//4294967294U = 11111111111111111111111111111110
	z1 = ((z1 & 4294967294U) << 18) ^ b;
	b = ((z2 << 2) ^ z1) >> 27;
	//4294967288U = 11111111111111111111111111111000
	z2 = ((z2 & 4294967288U) << 2) ^ b;
	b = ((z3 << 13) ^ z3) >> 21;
	//4294967280U = 11111111111111111111111111110000
	z3 = ((z3 & 4294967280U) << 7) ^ b;
	b = ((z4 << 3) ^ z4) >> 12;
	//4294967168U = 11111111111111111111111110000000
	z4 = ((z4 & 4294967168U) << 13) ^ b;
	return (z1 ^z2 ^ z3 ^z4);
}

// Creates an array automatically determined at compilation with a static 100x100 size.
double autoArray100(bool isCol=false){
	unsigned int r,c;
	clock_t start = 0;
	//alternate 2D array allocation - 
	auto soo = new double[size100][size100];

    for(r=0;r<size100;r++)
		for(c=0;c<size100;c++)
			soo[r][c] = r+c;

    if(isCol){
	    //cout << "auto soo array - col major #1" << endl;
	    start = clock();
	    for(c=1;c<size100;c++)
		    for(r=1;r<size100;r++)
			    soo[r][c] = soo[r][c-1];
    }
	else{
	    //cout << "auto soo array - row major #1" << endl;
	    start = clock();
	    for(r=1;r<size100;r++)
		    for(c=1;c<size100;c++)
			    soo[r][c] = soo[r][c-1];
    }
	delete soo;
    return (double) ( clock() - start)/CLOCKS_PER_SEC;
}

// Creates an array automatically determined at compilation with a static 1000x1000 size.
double autoArray1000(bool isCol=false){
	unsigned int r,c;
	clock_t start = 0;
	//alternate 2D array allocation - 
	auto soo = new double[size1000][size1000];

    for(r=0;r<size1000;r++)
		for(c=0;c<size1000;c++)
			soo[r][c] = r+c;

    if(isCol){
	    //cout << "auto soo array - col major #1" << endl;
	    start = clock();
	    for(c=1;c<size1000;c++)
		    for(r=1;r<size1000;r++)
			    soo[r][c] = soo[r][c-1];
    }
	else{
	    //cout << "auto soo array - row major #1" << endl;
	    start = clock();
	    for(r=1;r<size1000;r++)
		    for(c=1;c<size1000;c++)
			    soo[r][c] = soo[r][c-1];
    }
	delete soo;
    return (double) ( clock() - start)/CLOCKS_PER_SEC;
}

// Creates an array automatically determined at compilation with a static 10000x10000 size.
double autoArray10000(bool isCol=false){
	unsigned int r,c;
	clock_t start = 0;
	//alternate 2D array allocation - 
	auto soo = new double[size10000][size10000];

    for(r=0;r<size10000;r++)
		for(c=0;c<size10000;c++)
			soo[r][c] = r+c;

    if(isCol){
	    //cout << "auto soo array - col major #1" << endl;
	    start = clock();
	    for(c=1;c<size10000;c++)
		    for(r=1;r<size10000;r++)
			    soo[r][c] = soo[r][c-1];
    }
	else{
	    //cout << "auto soo array - row major #1" << endl;
	    start = clock();
	    for(r=1;r<size10000;r++)
		    for(c=1;c<size10000;c++)
			    soo[r][c] = soo[r][c-1];
    }
	delete soo;
    return (double) ( clock() - start)/CLOCKS_PER_SEC;
}

// Creates a 2D array by mapping a 1D array.
double mappedArray(size_t size, bool isCol=false){
    unsigned int r,c;
    clock_t start = 0;
    	// 1D array mapped to 2D using r*NumRows+col
	unsigned long long *boo = new unsigned long long [size*size];

    	// this loads things into cache - not sure it will make a difference.
	for(r=0;r<size;r++)
		for(c=0;c<size;c++)
			boo[r*size+c] = r+c;
	
    if(isCol){
	    // cout << "col major #1 -- c type array" << endl;
	    start = clock();
	    for(c=1;c<size;c++)
		    for(r=1;r<size;r++)
			    boo[r*size+c] = boo[r*size+(c-1)];

    }
    else{
	    // cout << "row major #2 -- C type array" << endl;
	    start = clock();
	    for(r=1;r<size;r++)
		    for(c=1;c<size;c++)
			    boo[r*size+c] = boo[r*size+(c-1)];
				
    }
    delete boo;
    return (double) ( clock() - start)/CLOCKS_PER_SEC;
    
}

// Creates a 2D array by having an array of pointers to another array. 
double arrayOfPointers(size_t size, bool isCol=false){
	unsigned int r,c;
    clock_t start = 0;	
	// 2D array of pointers to arrays
    unsigned long long **foo = new unsigned long long* [size];
	for(int i=0;i<size;i++) foo[i]=new unsigned long long [size];
	
	// this loads things into cache - not sure it will make a difference.
	for(r=0;r<size;r++)
		for(c=0;c<size;c++)
			foo[r][c] = r+c;

     if(isCol){
	    // cout << "col major -- array of pointers to arrays" << endl;
	    for(c=1;c<size;c++)
		    for(r=1;r<size;r++)
			    foo[r][c] = foo[r][c-1];

    }
	else{
        //	cout << "row major -- array of pointers to arrays" << endl;
        start = clock();
	    for(r=1;r<size;r++)
		    for(c=1;c<size;c++)
			    foo[r][c] = foo[r][c-1];
			
	}
    delete foo;
    return (double) ( clock() - start)/CLOCKS_PER_SEC;
}


int main() {
    // PT 1 and compiling with gcc flag -O0 and then -O3
    cout << "PT 1 Comparing averages over 5 times with high optimization and rows first" << endl;
    double d1time;
    double d2time;
    double d3time;
    int size;

    for(int i=2; i<=4; i++){
        d1time = 0;
        d2time = 0;
        d3time = 0;
        for(int x=0; x<5; x++){
            size = pow(10,i);
            if(size == 100){
                // d1time and d2time are included in here just to make sure they run in roughly the sameway
                d1time += mappedArray(size, false);
                d2time += arrayOfPointers(size, false);
                d3time += autoArray100(false);
                }
            else if(size == 1000){
                // d1time and d2time are included in here just to make sure they run in roughly the sameway
                d1time += mappedArray(size, false);
                d2time += arrayOfPointers(size, false);
                d3time += autoArray1000(false);
                }
            else{
                // d1time and d2time are included in here just to make sure they run in roughly the sameway
                d1time += mappedArray(size, false);
                d2time += arrayOfPointers(size, false);
                d3time += autoArray10000(false);
                }
            }
        d1time /= 5;
        d2time /= 5;
        d3time /= 5;
        cout << "The average time it takes for a " << size << " mapped array to run 5 times is " << d1time << endl;
        cout << "The average time it takes for a " << size << " array of pointers to run 5 times is " << d2time << endl;
        cout << "The average time it takes for an " << size << " auto array to run 5 times is " << d3time << endl;
    }
    
    cout << endl;
    cout << "PT 1 Comparing averages over 5 times with high optimization and columns first" << endl;
        for(int i=2; i<=4; i++){
        d1time = 0;
        d2time = 0;
        d3time = 0;
        for(int x=0; x<5; x++){
            size = pow(10,i);
            if(size == 100){
                // d1time and d2time are included in here just to make sure they run in roughly the sameway
                d1time += mappedArray(size, true);
                d2time += arrayOfPointers(size, true);
                d3time += autoArray100(true);
                }
            else if(size == 1000){
                // d1time and d2time are included in here just to make sure they run in roughly the sameway
                d1time += mappedArray(size, true);
                d2time += arrayOfPointers(size, true);
                d3time += autoArray1000(true);
                }
            else{
                // d1time and d2time are included in here just to make sure they run in roughly the sameway
                d1time += mappedArray(size, true);
                d2time += arrayOfPointers(size, true);
                d3time += autoArray10000(true);
                }
            }
        d1time /= 5;
        d2time /= 5;
        d3time /= 5;
        cout << "The average time it takes for a " << size << " mapped array to run 5 times is " << d1time << endl;
        cout << "The average time it takes for a " << size << " array of pointers to run 5 times is " << d2time << endl;
        cout << "The average time it takes for an " << size << " auto array to run 5 times is " << d3time << endl;
    }

    // PT 2 and compiling with gcc flag -O0 and then -O3
    cout << endl;
    cout << "PT 2 Comparing runtime of rand, default_random_engine, and randFoo" << endl;
    const long long repeat = 99U;
	long long i1, i2, foo=1;
    double r1time, r2time, r3time = 0;
	
	clock_t start = clock();
	for (i1=0;i1<repeat;i1++)
		for (i2=0;i2<repeat;i2++){
			foo+=rand();
			foo-=rand();
		}
    r1time = ((double) ( clock() - start)/CLOCKS_PER_SEC)/repeat;
	cout << r1time << " is the average time it takes for rand() to run 99 times." << endl;
	
	// alternate rand
	start = clock();
	for (i1=0;i1<repeat;i1++)
		for (i2=0;i2<repeat;i2++){
			foo+=randFoo();
			foo-=randFoo();
		}
	r2time = ((double) ( clock() - start)/CLOCKS_PER_SEC)/repeat;
	cout << r2time << " is the average time it takes for randFoo() to run 99 times." << endl;			
	
	default_random_engine e(43);
	for(int soo=0;soo<repeat;soo++) {
        foo+=e();
        foo-=e();
    }
    r3time = ((double) ( clock() - start)/CLOCKS_PER_SEC)/repeat;
	cout << r3time << " is the average time it takes for default_random_engine to run 99 times." << endl;

	return 0;
}
