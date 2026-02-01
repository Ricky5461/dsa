@echo off
:: Compiles the file using g++
g++ %1.cpp -o %1.exe

:: If compilation is successful, run the executable
if %errorlevel% equ 0 (
    echo --- Running %1.exe ---
    %1.exe
)