#include <stdio.h>

int main(void) {
    long long temp = 0x00000000, N, d1, d2, d3, d4;
    scanf("%lld%lld%lld%lld%lld", &N, &d1, &d2, &d3, &d4);
    long long array[5] = {-1, N >> 24, (N & 0x00FF0000) >> 16, (N & 0x0000FF00) >> 8, N & 0x000000FF};
    temp ^= ((array[d1] ^ array[d2]) << 24);
    temp ^= ((array[d2] & array[d3]) << 16);
    temp ^= ((array[d3] | array[d1]) << 8);
    temp ^= (~array[d4] & 0x000000FF);
    temp &= 0xFFFFFFFF;
    for (int i = 0; i < (d1 + d2 + d3 + d4); i++) {
        if ((temp % 2) != 0) {
            temp >>= 1;
            temp += 0x80000000;
        } else {
            temp >>= 1;
        }
    }
    printf("%lld", ((temp & 0xFFFF0000) >> 16) ^ (temp & 0x0000FFFF));
    return 0;
}