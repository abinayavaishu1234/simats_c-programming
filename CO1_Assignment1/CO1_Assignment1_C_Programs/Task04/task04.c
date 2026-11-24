/* Task 4: Safe preprocessor macros */
#include <stdio.h>

#define SQUARE(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define RUPEES_TO_PAISE(x) ((x) * 100)

int main(void)
{
    int a = 5;
    int b = 10;

    printf("Square of 5 = %d\n", SQUARE(a));
    printf("Maximum value = %d\n", MAX(a, b));
    printf("Rupees to paise = %d\n", RUPEES_TO_PAISE(50));
    printf("Square of (a+1) = %d\n", SQUARE(a + 1));

    /* Avoid expressions with side effects such as MAX(i++, j). */
    return 0;
}
