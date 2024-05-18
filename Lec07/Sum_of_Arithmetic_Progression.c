#include <stdio.h>

int a_1, a_n, d;

int sum(int a_i);

int main() {
    scanf("%d %d %d", &a_1, &a_n, &d);
    printf("%d", sum(a_1));
    return 0;
}

int sum(int a_i) {
    int n, sum = 0;
    n = (a_n - a_1) / d + 1;
    for (int i = 0; i < n; i++) {
        sum += a_1 + d * i;
    }
    return sum;
}