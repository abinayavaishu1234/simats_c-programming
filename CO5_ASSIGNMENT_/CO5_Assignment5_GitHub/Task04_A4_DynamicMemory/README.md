# Task A4 – Design Dynamic Memory Use

**Compile:** `gcc -std=c11 -Wall -Wextra -pedantic main.c -o program`  
**Run:** `./program`

The donor list starts with capacity 2 and doubles whenever full. `realloc` is assigned to a temporary pointer so that the original allocation is not lost if allocation fails.
