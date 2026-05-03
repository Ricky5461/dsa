@echo off
g++ %1.cpp -o %1.exe
if %errorlevel% equ 0 (
    %1.exe
)