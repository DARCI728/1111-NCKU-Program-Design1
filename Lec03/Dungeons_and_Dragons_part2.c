#include <stdio.h>

int main() {
    int d1, d2, d3, d4, d5, d6, player_life = 100, dragon_life = 100;
    while (player_life > 0 && dragon_life > 0) {
        scanf("%d %d %d %d %d %d", &d1, &d2, &d3, &d4, &d5, &d6);
        if (((d1 + d2 + d3) % 2) != 0) {
            if (d4 < d5 && d5 < d6) {
                dragon_life -= 25;
            } else if ((d4 % 2 == d5 % 2) || (d5 % 2 == d6 % 2)) {
                dragon_life -= 5;
            }
        } else {
            if (((d4 - d5) > d6) || ((d5 - d4) > d6)) {
                player_life -= 15;
            } else if (d4 + d5 != d6) {
                player_life -= 5;
            }
        }
    }
    if (dragon_life <= 0) {
        printf("Player wins");
    } else if (player_life <= 0) {
        printf("Dragon wins");
    }
    return 0;
}