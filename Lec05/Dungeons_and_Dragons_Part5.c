#include <stdio.h>

int main() {
    int i = 0, d1, d2, code[7] = {0, 100, 100, 100, 100, 100, 100};
    while (i < 75) {
        scanf("%d%d", &d1, &d2);
        if (d2 % 2 > 0) {
            code[d1] += 1;
        } else {
            code[d1] -= 1;
        }
        i++;
    }
    printf("%d %d %d %d %d %d", code[1] % 10, code[2] % 10, code[3] % 10, code[4] % 10, code[5] % 10, code[6] % 10);
    return 0;
}