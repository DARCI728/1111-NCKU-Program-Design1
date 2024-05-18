#include <stdio.h>

int IEEE_754(float n);

int main(void) {
    int a, b, sum = 0;
    scanf("%d%d", &a, &b);
    printf("   ");
    sum += IEEE_754(a);
    printf("\n+) ");
    sum += IEEE_754(b);
    printf("\n---------------------------------------\n   ");
    for (int i = 31; i >= 0; i--) {
        printf("%d", (sum >> i) & 0b1);
        if (i == 24 || i == 16 || i == 8)
            printf(" ");
    }
    printf("\n%d + %d = %d", a, b, sum);
    return 0;
}

int IEEE_754(float n) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (*(int *)&n >> i) & 1);
        if (i == 24 || i == 16 || i == 8) printf(" ");
    }
    return *(int *)&n;
}