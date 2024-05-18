#include <stdio.h>

unsigned long construct(unsigned char parts[16]);

int main() {
    unsigned char parts[16];
    for (int i = 0; i < 16; i++)
        scanf("%hhx", parts + i);

    printf("%lu", construct(parts));

    return 0;
}

unsigned long construct(unsigned char parts[16]) {
    unsigned long long parts_cpy[16];
    unsigned long long l1 = 0, l2 = 0;
    for (int i = 0; i < 16; i++)
        parts_cpy[i] = parts[i];
    for (int i = 7; i > -1; i--) {
        l1 |= parts_cpy[i] << 8 * i;
        l2 |= parts_cpy[i + 8] << 8 * i;
    }
    return l1 ^ l2;
}