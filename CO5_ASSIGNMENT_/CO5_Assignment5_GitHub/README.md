# CSA02 – C Programming – Assignment 5 (CO5)

**Topic:** Modular, Memory-Aware and Persistent Program Engineering  
**Language:** C (C11)  
**Compiler example:** GCC

This repository is organized into one folder for each assignment task. The assignment's Part A (A1–A5) primarily asks for design, pseudocode and analysis; these folders also contain small C demonstrations to help test the designs. Part B (B1–B4) contains the implementation programs.

## Folder guide

| Folder | Assignment task | Main file |
|---|---|---|
| `Task01_A1_Functions` | Functional decomposition and interfaces | `main.c` |
| `Task02_A2_Recursion` | Recursive digital root and power | `main.c` |
| `Task03_A3_Pointers` | Pointer operations and stock lookup | `main.c` |
| `Task04_A4_DynamicMemory` | Growable donor list using `realloc` | `main.c` |
| `Task05_A5_FileStorage` | Text donor file and binary stock file | `main.c` |
| `Task06_B1_RecursiveFunctions` | Instrumented recursive functions | `main.c` |
| `Task07_B2_AdversarialInputs` | Input validation and error handling | `main.c` |
| `Task08_B3_B4_Engineering` | Text/binary comparison and donor report | `main.c` |

## Compile and run

Open a terminal in the required task folder.

```bash
gcc -std=c11 -Wall -Wextra -pedantic main.c -o program
./program
```

On Windows with MinGW:

```bash
gcc -std=c11 -Wall -Wextra -pedantic main.c -o program.exe
program.exe
```

Some folders accept command-line arguments. Run `./program --help` where available, or read that folder's README.

## Important notes

- The records in this project are **synthetic demonstration data only**. Do not add real donor personal information to a public repository.
- Run each program on your own computer and save your actual terminal screenshots in the corresponding task folder before submission.
- Timing and memory results depend on the computer, compiler and operating system. The programs print measurements where applicable; record your own results rather than treating sample timings as universal.
- `Task07_B2_AdversarialInputs` demonstrates safe input handling. The unsafe `scanf("%s")` case is explained in comments rather than intentionally overflowing a buffer.
- Part A design answers (structure chart, pseudocode, call traces, memory diagram and complexity discussion) should be added to your report. C programs alone do not replace the required pseudocode.

## GitHub setup

1. Create a repository named `CSA02-<RegisterNumber>-Assignment5`.
2. Extract this ZIP file.
3. Open a terminal in the extracted `CO5_Assignment5_GitHub` folder.
4. Run:

```bash
git init
git add .
git commit -m "Add Assignment 5 task programs"
git branch -M main
git remote add origin https://github.com/<YourUsername>/CSA02-<RegisterNumber>-Assignment5.git
git push -u origin main
```

5. For the assignment requirement of progressive commits, make a separate commit after you test and add evidence for each task, for example:

```bash
git add Task01_A1_Functions
git commit -m "Complete Task A1 function design demo"
git push
```

Repeat for each task folder. Do not claim progressive commits if you only make one final commit.

## Compiler information to fill in

- Student name: ____________________
- Register number: ____________________
- Compiler and version: ____________________
- Operating system: ____________________
- GitHub repository URL: ____________________
