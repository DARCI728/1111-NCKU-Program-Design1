#include <stdio.h>

int main(void) {
    long long EAN;
    int a = 0, b = 0, x, y, z, i;
    scanf("%lld", &EAN);
    for (i = 0; i < 6; i++) {
        a += EAN % 10;
        EAN /= 10;
        b += EAN % 10;
        EAN /= 10;
    }
    x = a * 3 + b;
    y = x - 1;
    z = y % 10;
    printf("%d", 9 - z);
    return 0;
}