#include <stdio.h>

int main() {
    long long int n, x, y = 0;
    scanf("%lld", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &x);
        y += x;
        if (y % x == 0) {
            printf("%lld %lld\n", y, x);
        }
    }
    return 0;
}
