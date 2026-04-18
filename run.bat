@echo off
cmake -B build
cmake --build build
cd build
GLbasic.exe
cd ..