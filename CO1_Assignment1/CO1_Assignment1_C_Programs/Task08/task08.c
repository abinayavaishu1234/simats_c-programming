/* Task 8: Source program for demonstrating GCC compilation stages */
#include <stdio.h>

#define FIXED_CHARGE 50

int main(void)
{
    int units = 150;
    float bill = FIXED_CHARGE + (units - 100) * 2.25f;

    printf("Units = %d\n", units);
    printf("Total Bill = Rs %.2f\n", bill);
    return 0;
}
