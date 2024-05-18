#include <stdio.h>

int main() {
    int max = 0, min = 0, n;
    scanf("%d", &n);
    min = n;
    while (scanf("%d", &n), n != -1) {
        if (n >= max) {
            max = n;
        } else if (min >= n) {
            min = n;
        }
    }
    printf("%d", max - min);
    return 0;
}
