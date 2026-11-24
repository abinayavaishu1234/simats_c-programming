/* Task 10: Compare totals for different household counts */
#include <stdio.h>
#include <limits.h>

int main(void)
{
    const long long bill_paise = 16250LL;
    const long long households[] = {4000LL, 60000LL, 800000LL};
    int n = (int)(sizeof households / sizeof households[0]);

    printf("INT MAX = %d\n", INT_MAX);
    printf("LONG LONG MAX = %lld\n", LLONG_MAX);

    for (int i = 0; i < n; i++) {
        long long total = bill_paise * households[i];
        printf("\nHouseholds = %lld\n", households[i]);
        printf("Total in paise = %lld\n", total);
        printf("Total in rupees = %lld.%02lld\n",
               total / 100, total % 100);
    }
    return 0;
}
