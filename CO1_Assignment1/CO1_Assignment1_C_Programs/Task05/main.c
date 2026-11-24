/* Task 5: Header file and conditional compilation */
#include <stdio.h>
#include "billing.h"

long calculate_bill(int units)
{
    long bill = FIXED_CHARGE_PAISE;

    if (units > 200)
        bill += 100L * 225 + (long)(units - 200) * 450;
    else if (units > 100)
        bill += (long)(units - 100) * 225;

    return bill;
}

int main(void)
{
    int units = 150;
    long bill = calculate_bill(units);

#ifdef DEBUG
    printf("Debug: Units = %d\n", units);
    printf("Debug: Bill in paise = %ld\n", bill);
#endif

    printf("Total Bill = Rs %ld.%02ld\n", bill / 100, bill % 100);
    return 0;
}
