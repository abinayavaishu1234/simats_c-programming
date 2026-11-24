/* Task 12: Smart meter billing with peak-hour tariff.
   Rate is entered at runtime in paise per kWh.
   Charges are rounded to the nearest paise. */
#include <stdio.h>
#include <limits.h>

int main(void)
{
    long long normal_wh, peak_wh;
    long long rate_paise;
    const long long fixed_charge_paise = 5000LL;
    long long energy_charge_paise;
    long long numerator;

    printf("Enter normal-hour consumption (Wh): ");
    if (scanf("%lld", &normal_wh) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    printf("Enter peak-hour consumption (Wh): ");
    if (scanf("%lld", &peak_wh) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    printf("Enter tariff rate (paise per kWh): ");
    if (scanf("%lld", &rate_paise) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    if (normal_wh < 0 || peak_wh < 0 || rate_paise < 0) {
        printf("Values cannot be negative.\n");
        return 1;
    }

    /* 100 Wh? No: 1000 Wh = 1 kWh.
       Peak units cost 120% of the normal rate.
       Numerator is in paise*Wh*100; divide by 100000. */
    numerator = normal_wh * rate_paise * 100LL
              + peak_wh * rate_paise * 120LL;

    energy_charge_paise = (numerator + 50000LL) / 100000LL;
    printf("\nNormal consumption: %lld Wh\n", normal_wh);
    printf("Peak consumption: %lld Wh\n", peak_wh);
    printf("Energy charge: Rs %lld.%02lld\n",
           energy_charge_paise / 100, energy_charge_paise % 100);

    printf("Total Bill: Rs %lld.%02lld\n",
           (energy_charge_paise + fixed_charge_paise) / 100,
           (energy_charge_paise + fixed_charge_paise) % 100);

    return 0;
}
