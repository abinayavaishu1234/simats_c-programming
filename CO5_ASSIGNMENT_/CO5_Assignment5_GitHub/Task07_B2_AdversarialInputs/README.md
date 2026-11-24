# Task B2 – Engineer Adversarial Inputs

**Compile:** `gcc -std=c11 -Wall -Wextra -pedantic main.c -o program`  
**Run:** `./program "A very long donor name"`  
**Try invalid arguments:** `./program` or `./program "Name" BAD`

The program validates argument count and blood group, reads a name with `fgets`, checks file errors with `perror`, and avoids writing beyond fixed-size buffers.

The assignment asks to compare `scanf("%s")` and `fgets`. An unbounded `%s` can overflow a destination array when the input is too long. This demonstration does not intentionally execute an unsafe overflow; use the explanation in your report.
