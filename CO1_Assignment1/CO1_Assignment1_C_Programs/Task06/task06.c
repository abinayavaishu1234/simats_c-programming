/* Task 6: Formatted input/output and input validation */
#include <stdio.h>

int main(void)
{
    int previous, current;
    unsigned int units;
    long bill = 5000L;

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

    if (current >= previous)
        units = (unsigned int)(current - previous);
    else
        units = 65536U - (unsigned int)previous + (unsigned int)current;

    if (units > 200)
        bill += 100L * 225 + (long)(units - 200) * 450;
    else if (units > 100)
        bill += (long)(units - 100) * 225;

    printf("Units consumed: %u\n", units);
    printf("Total Bill: Rs %ld.%02ld\n", bill / 100, bill % 100);
    return 0;
}
