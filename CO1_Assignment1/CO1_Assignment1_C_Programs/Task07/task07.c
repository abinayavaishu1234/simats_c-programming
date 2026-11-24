/* Task 7: Type conversion and precision examples */
#include <stdio.h>

int main(void)
{
    int a = 5, b = 2;
    float x = 5.0f;
    double amount = 162.50;

    printf("Integer division = %d\n", a / b);
    printf("Floating division = %.2f\n", x / b);
    printf("Type casting = %.2f\n", (float)a / b);
    printf("10 / 3 as integer = %d\n", 10 / 3);
    printf("10 / 3 as floating point = %.4f\n", 10.0 / 3.0);
    printf("Amount = %.2f\n", amount);

    return 0;
}
