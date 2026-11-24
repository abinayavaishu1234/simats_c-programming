# Task A1 – Decompose the Program into Functions

This demo separates donor registration, eligibility checking, searching and stock updating into functions. It uses a small in-memory sample.

**Compile:** `gcc -std=c11 -Wall -Wextra -pedantic main.c -o program`  
**Run:** `./program`

## Interface notes
- `register_donor`: receives a pointer because it writes into the donor array.
- `is_eligible`: receives a pointer to a donor that it only reads (`const`).
- `find_eligible`: receives a read-only donor array and writes count/youngest ID through output pointers.
- `update_stock`: receives the stock array by pointer because it modifies one element.

## Structure chart
```text
main
 ├── register_donor
 ├── find_eligible
 │    └── is_eligible
 └── update_stock
```

The program demonstrates one possible interface design. In the report, compare output parameters with returning a structure, and explain why global variables increase coupling even though they do not change the basic Big-O running time.
