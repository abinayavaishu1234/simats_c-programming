/* Task 9: Complete billing program with basic validation and rollover */
#include <stdio.h>

#define FIXED_CHARGE_PAISE 5000L
#define RATE2_PAISE 225L
#define RATE3_PAISE 450L

int main(void)
{
    int previous, current;
    unsigned int units;
    long energy_charge = 0;
    long total_bill;

    printf("Enter previous reading: ");
    if (scanf("%d", &previous) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    printf("Enter current reading: ");
    if (scanf("%d", &current) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    if (previous < 0 || previous > 65535 ||
        current < 0 || current > 65535) {
        printf("Invalid meter reading!\n");
        return 1;
    }

    /* A lower current value is treated as one register rollover. */
    if (current >= previous)
        units = (unsigned int)(current - previous);
    else
        units = 65536U - (unsigned int)previous + (unsigned int)current;

    if (units <= 100)
        energy_charge = 0;
    else if (units <= 200)
        energy_charge = (long)(units - 100) * RATE2_PAISE;
    else
        energy_charge = 100L * RATE2_PAISE +
                        (long)(units - 200) * RATE3_PAISE;

    total_bill = FIXED_CHARGE_PAISE + energy_charge;

    printf("\nUnits consumed: %u\n", units);
    printf("Energy charge: Rs %ld.%02ld\n",
           energy_charge / 100, energy_charge % 100);
    printf("Total bill: Rs %ld.%02ld\n",
           total_bill / 100, total_bill % 100);

    return 0;
}
