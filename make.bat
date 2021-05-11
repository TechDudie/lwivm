@echo off
mkdir bin
gcc src/lwivm.c -o bin/lwivm.exe
gcc src/assembler.c -o bin/assembler.exe
gcc src/compiler.c -o bin/compiler.exe
