# Task A5 – Design the File Storage

**Compile:** `gcc -std=c11 -Wall -Wextra -pedantic main.c -o program`  
**Run:** `./program`

The program writes donor details as readable text and stock records as fixed-size binary structures. It then updates one binary record using `fseek`, `fread` and `fwrite`.

Running the program creates `donors.txt` and `stock.bin` in the current directory. These are generated demonstration files.
