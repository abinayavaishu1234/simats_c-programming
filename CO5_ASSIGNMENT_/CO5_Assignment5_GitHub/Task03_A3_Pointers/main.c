#include <stdio.h>

int *lowest_stock(int stock[], int count) {
    if (count <= 0) return NULL;
    int *lowest = &stock[0];
    for (int i = 1; i < count; i++) {
        if (stock[i] < *lowest) lowest = &stock[i];
    }
    return lowest; /* points into caller-owned array, not a local variable */
}

int main(void) {
    int stock[8] = {40, 25, 12, 8, 30, 18, 22, 14};
    int *p = stock;

    printf("p + 3 points to element 3\n");
    printf("*(p + 3) = %d\n", *(p + 3));
    printf("p[3] = %d\n", p[3]);
    printf("*p++ = %d\n", *p++);
    printf("After pointer increment, *p = %d\n", *p);

    int *lowest = lowest_stock(stock, 8);
    if (lowest != NULL) {
        printf("Lowest stock = %d\n", *lowest);
        *lowest += 5;
        printf("Updated lowest element = %d\n", *lowest);
    }
    return 0;
}
