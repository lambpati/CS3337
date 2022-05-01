cmake_minimum_required(VERSION 3.20)

project(FooTron)

include_directories(${PROJECT_SOURCE_DIR}, Examples)
add_executable(FooTronEmulator main.cpp ReadProgram.cpp Accumulator.cpp Arithmetic.cpp BranchIns.cpp InstructionConversion.cpp Memory.cpp ReadProgram.cpp readWriteLoadStore.cpp UserControl.cpp UserDisplay.cpp WriteProgram.cpp)
