@echo off
cls
cmake -S . -B ./build -G "MinGW Makefiles" 
cd build
make 
cd ../bin
start Chess.exe
cd ..