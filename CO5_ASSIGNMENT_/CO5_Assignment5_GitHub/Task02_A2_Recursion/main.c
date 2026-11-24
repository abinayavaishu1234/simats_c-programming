#include <stdio.h>

long long calls_linear = 0;
long long calls_fast = 0;

int digital_root(int n) {
    if (n < 0) n = -n;
    if (n < 10) return n;
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return digital_root(sum);
}

long long power_linear(long long base, int exp) {
    calls_linear++;
    if (exp == 0) return 1;
    return base * power_linear(base, exp - 1);
}

long long power_fast(long long base, int exp) {
    calls_fast++;
    if (exp == 0) return 1;
    long long half = power_fast(base, exp / 2);
    if (exp % 2 == 0) return half * half;
    return base * half * half;
}

int main(void) {
    printf("Digital root of 9875: %d\n", digital_root(9875));
    printf("2^10 linear: %lld\n", power_linear(2, 10));
    printf("Linear calls: %lld\n", calls_linear);
    printf("2^10 fast: %lld\n", power_fast(2, 10));
    printf("Fast calls: %lld\n", calls_fast);
    return 0;
}
