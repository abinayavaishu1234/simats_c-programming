/* Task 5: Automatic, static and register storage classes */
#include <stdio.h>

int next_token(void)
{
    static int token = 1000;
    return ++token;
}

int auto_token(void)
{
    int token = 1000;
    return ++token;
}

int main(void)
{
    int s1 = next_token(), s2 = next_token(), s3 = next_token();
    int a1 = auto_token(), a2 = auto_token(), a3 = auto_token();
    register int i;

    printf("static: %d %d %d\n", s1, s2, s3);
    printf("auto  : %d %d %d\n", a1, a2, a3);
    printf("register loop: ");
    for (i = 1; i <= 3; i++)
        printf("%d ", i);
    printf("\n");
    return 0;
}
