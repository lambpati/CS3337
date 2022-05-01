If you want to run FooTron code, make sure you have CMake 3.20 or above.

It is written with C++ 11 standards

To build, run:
```
mkdir build
cd build
cmake ../
cmake --build .
```
The program can be run with:
```
./FooTron
```
For ease of use, the paths from the build directory to the examples are included below to just copy paste:
```
../Examples/footronSample1.txt
../Examples/footronSample2.txt
../Examples/footronSample3.txt
```

Since GLIBC update, atom no longer runs normally until fix, run:
```
atom --no-sandbox
```
