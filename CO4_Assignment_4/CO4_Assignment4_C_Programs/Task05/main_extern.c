/* Two-file example: extern refers to a global defined in counter.c */
#include <stdio.h>
#include "counter.h"

int main(void)
{
    printf("extern: %d %d %d\n",
           issue_shared_token(), issue_shared_token(), issue_shared_token());
    return 0;
}
