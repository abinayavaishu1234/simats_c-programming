# Task A3 – Design with Pointers

**Compile:** `gcc -std=c11 -Wall -Wextra -pedantic main.c -o program`  
**Run:** `./program`

For `int *p = stock`, `p + 3` points to element 3, `*(p + 3)` reads element 3, `p[3]` is equivalent to `*(p + 3)`, and `*p++` reads the current element before advancing `p` (post-increment applies to the pointer).
