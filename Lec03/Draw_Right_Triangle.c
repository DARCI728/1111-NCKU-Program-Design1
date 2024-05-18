#include <stdio.h>

int main() {
    int i, j, a;
    scanf("%d%d", &i, &j);
    if (i == 1) {
        for (int k = j; k > 0; k--) {
            for (int a = k; a > 0; a--)
                printf("*");
            printf("\n");
        }
    } else if (i == 2) {
        for (int k = 1; k <= j; k++) {
            for (int a = 0; a < k; a++)
                printf("*");
            printf("\n");
        }
    } else if (i == 3) {
        for (int k = j; k > 0; k--) {
            for (int a = 0; a < j - k; a++)
                printf(" ");
            for (int b = 0; b < k; b++)
                printf("*");
            printf("\n");
        }
    } else {
        for (int k = j; k > 0; k--) {
            for (int a = 0; a < k - 1; a++)
                printf(" ");
            for (int b = 0; b <= j - k; b++)
                printf("*");
            printf("\n");
        }
    }
    return 0;
}
