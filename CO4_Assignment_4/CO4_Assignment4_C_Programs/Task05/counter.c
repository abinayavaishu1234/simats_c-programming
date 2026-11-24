#include "counter.h"
int shared_token = 1000;

int issue_shared_token(void)
{
    return ++shared_token;
}
