#include <stdio.h>

int main() {
    int a, b, count = 3;
    char IPv4_16[8];
    scanf("%s", IPv4_16);
    for (int i = 0; i < 8; i++) {
        if (IPv4_16[i] == 'a' || IPv4_16[i] == 'b' || IPv4_16[i] == 'c' || IPv4_16[i] == 'd' || IPv4_16[i] == 'e' || IPv4_16[i] == 'f') {
            a = (IPv4_16[i] - 'W') * 16;
        } else {
            a = (IPv4_16[i] - '0') * 16;
        }
        if (IPv4_16[i + 1] == 'a' || IPv4_16[i + 1] == 'b' || IPv4_16[i + 1] == 'c' || IPv4_16[i + 1] == 'd' || IPv4_16[i + 1] == 'e' || IPv4_16[i + 1] == 'f') {
            b = (IPv4_16[i + 1] - 'W');
        } else {
            b = (IPv4_16[i + 1] - '0');
        }
        i++;
        printf("%d", a + b);
        if (count > 0) {
            printf(".");
            count--;
        }
    }
    return 0;
}
