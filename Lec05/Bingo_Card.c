#include <stdio.h>

int main() {
    int n, sum = 0, count = 0, card[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            scanf("%d", &card[i][j]);
        }
    }
    for (int i = 0; i < 64; i++) {
        scanf("%d", &n);
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (card[i][j] == n) {
                    card[i][j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            sum += card[i][j];
        }
        if (sum == 0) {
            count += 1;
        }
        sum = 0;
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            sum += card[j][i];
        }
        if (sum == 0) {
            count += 1;
        }
        sum = 0;
    }
    if (card[0][0] + card[1][1] + card[2][2] + card[3][3] + card[4][4] + card[5][5] + card[6][6] + card[7][7] == 0) {
        count += 1;
    }
    if (card[0][7] + card[1][6] + card[2][5] + card[3][4] + card[4][3] + card[5][2] + card[6][1] + card[7][0] == 0) {
        count += 1;
    }
    printf("%d", count);
    return 0;
}
