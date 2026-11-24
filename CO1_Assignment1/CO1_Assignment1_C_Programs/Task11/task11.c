/* Task 11: Recommended final billing design */
#include <stdio.h>

#define FIXED_CHARGE_PAISE 5000L
#define RATE2_PAISE 225L
#define RATE3_PAISE 450L

long calculate_bill(unsigned int units)
{
    long bill = FIXED_CHARGE_PAISE;

    if (units > 200)
        bill += 100L * RATE2_PAISE +
                (long)(units - 200) * RATE3_PAISE;
    else if (units > 100)
        bill += (long)(units - 100) * RATE2_PAISE;

    return bill;
}

int main(void)
{
    unsigned int units = 350;
    long bill = calculate_bill(units);

    printf("Units consumed: %u\n", units);
    printf("Total Bill: Rs %ld.%02ld\n", bill / 100, bill % 100);
    return 0;
}
