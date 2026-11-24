CO1 ASSIGNMENT 1 - C PROGRAMS

Compiler:
GCC (MinGW GCC, installed with Code::Blocks)

Compile and run a single-file task:
    gcc task01.c -o task01
    .\task01.exe

For Task 5 (two files):
    gcc main.c -o billing
    .\billing.exe

For Task 5 with debug messages:
    gcc -DDEBUG main.c -o billing
    .\billing.exe

For Task 8 compilation stages:
    gcc -E task08.c -o task08.i
    gcc -S task08.c -o task08.s
    gcc -c task08.c -o task08.o
    gcc task08.o -o task08
    .\task08.exe

Each task has its own folder. Task 1 is primarily a problem-analysis task in the assignment;
its program is a small demonstration of the identified data items.

IMPORTANT:
Run and verify every program on your own computer. Capture your actual output screenshots.
Task 9 treats a lower current reading as one meter rollover; in a real system, an independent
rollover flag or validation rule is needed to distinguish rollover from an incorrect reading.
Task 12 uses runtime-entered tariff rate and rounds the combined charge to the nearest paise.
