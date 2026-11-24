# Tasks B3 and B4 – File Comparison and Engineering Decision

**Compile:** `gcc -std=c11 -O2 -Wall -Wextra -pedantic main.c -o program`  
**Run:** `./program [number-of-records]`  
Example: `./program 10000`

The program:
- writes and reads donor records in text and binary formats;
- reports file sizes and elapsed CPU time;
- updates a selected binary record in place;
- demonstrates a growable donor list and prints a simple eligibility report;
- frees allocated memory before exit.

Run with 1000, 10000 and 100000 records and record the output on your own computer. Timings are environment-dependent. The assignment asks for a separate text-file rewrite timing for the 50,000th record; this program includes a simple rewrite comparison for the selected record.
