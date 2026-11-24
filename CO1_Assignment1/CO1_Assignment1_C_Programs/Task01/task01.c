/* Task 1: Identify and display the data used in the billing problem */
#include <stdio.h>

int main(void)
{
    int household_number = 101;
    char category = 'D';
    unsigned short previous_reading = 1200;
    unsigned short current_reading = 1350;
    unsigned int units;
    long energy_charge_paise;
    long fixed_charge_paise = 5000L;
    long total_paise;

    units = (unsigned short)(current_reading - previous_reading);

    if (units <= 100)
        energy_charge_paise = 0;
    else if (units <= 200)
        energy_charge_paise = (long)(units - 100) * 225;
    else
        energy_charge_paise = 100L * 225 + (long)(units - 200) * 450;

    total_paise = fixed_charge_paise + energy_charge_paise;

    printf("Household number: %d\n", household_number);
    printf("Category: %c\n", category);
    printf("Previous reading: %hu\n", previous_reading);
    printf("Current reading: %hu\n", current_reading);
    printf("Units consumed: %u\n", units);
    printf("Energy charge: Rs %ld.%02ld\n",
           energy_charge_paise / 100, energy_charge_paise % 100);
    printf("Fixed charge: Rs %ld.%02ld\n",
           fixed_charge_paise / 100, fixed_charge_paise % 100);
    printf("Total bill: Rs %ld.%02ld\n",
           total_paise / 100, total_paise % 100);

    return 0;
}
