@echo off
title Quiz Management System

echo ==================================
echo     Quiz Management System
echo ==================================
echo.

echo Compiling project...
g++ main.cpp -o QuizManagementSystem.exe

if %errorlevel% neq 0 (
    echo.
    echo Compilation failed!
    pause
    exit
)

echo.
echo Running Quiz Management System...
QuizManagementSystem.exe

pause