#include <stdio.h>

int main() {
    int N, score[1023], times, c1, c2, c3, A, B;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &score[i]);
    }
    scanf("%d", &times);
    for (int i = 0; i < times; i++) {
        c1 = 0, c2 = 0, c3 = 0;
        scanf("%d%d", &B, &A);
        for (int i = 0; i < N; i++) {
            if (score[i] < B) {
                c1 += 1;
            } else if (B <= score[i] && score[i] < A) {
                c2 += 1;
            } else {
                c3 += 1;
            }
        }
        printf("%d %d %d\n", c1, c2, c3);
    }
    return 0;
}
