#include <stdio.h>

int main() {
    long long N = 0x7CE66C50E2840000LLU, NUMBER_1 = 0x38E38E38E38E3800LLU, NUMBER_2 = 0x2AAAAAAAAAAAAAAALLU, NUMBER_3 = 0x1C71C71C71C71C71LLU;
    int d1, d2, d3;
    scanf("%d%d%d", &d1, &d2, &d3);
    printf("%lld", (((d1 * NUMBER_1) % N + (d2 * NUMBER_2) % N) % N + (d3 * NUMBER_3) % N) % N);
    return 0;
}
