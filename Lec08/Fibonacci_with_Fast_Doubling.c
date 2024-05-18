#include <stdio.h>

typedef unsigned long long uint64_t;

void fib_fast_doubling(unsigned k, uint64_t *f2k, uint64_t *f2k1);

int main() {
    unsigned k;
    scanf("%u", &k);

    uint64_t f2k, f2k1;
    fib_fast_doubling(k / 2, &f2k, &f2k1);

    printf("%llu", (k & 0x1) ? f2k1 : f2k);

    return 0;
}

void fib_fast_doubling(unsigned k, uint64_t *f2k, uint64_t *f2k1) {
    unsigned long long fk = 1, fk1 = 2;
    if (k == 0) {
        *f2k1 = 1;  // k = 1
    } else if (k == 1) {
        *f2k = 1;   // k = 2
        *f2k1 = 2;  // k = 3
    } else if (k == 2) {
        *f2k = 3;   // k = 4
        *f2k1 = 5;  // k = 5
    } else if (k == 3) {
        *f2k = 8;    // k = 6
        *f2k1 = 13;  // k = 7
    } else {
        if (k % 2 == 1) {
            fib_fast_doubling(k / 2, f2k, f2k1);
            fk = *f2k1;
            fib_fast_doubling(k / 2 + 1, f2k, f2k1);
            fk1 = *f2k;
        } else {
            fib_fast_doubling(k / 2, f2k, f2k1);
            fk = *f2k;
            fk1 = *f2k1;
        }
        *f2k = fk * (2 * fk1 - fk);
        *f2k1 = fk * fk + fk1 * fk1;
    }
}