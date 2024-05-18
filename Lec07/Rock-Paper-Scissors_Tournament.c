#include <stdio.h>

void who_win(int n, int cnt, char player[10000], char judge[10000], int win[10000]);

int main() {
    int n, cnt = 0, win[10000] = {0};
    char player[10000], judge[10000];
    scanf("%d", &n);
    scanf("%s", player);
    scanf("%s", judge);
    for (int i = 0; i < n; i++) {
        win[i] = i;
    }
    who_win(n, cnt, player, judge, win);
    return 0;
}

void who_win(int n, int cnt, char p[10000], char judge[10000], int win[10000]) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (p[win[i]] == 'p' && p[win[i + 1]] == 's') {
            win[j++] = win[i + 1];
        } else if (p[win[i]] == 'p' && p[win[i + 1]] == 'r') {
            win[j++] = win[i];
        } else if (p[win[i]] == 's' && p[win[i + 1]] == 'p') {
            win[j++] = win[i];
        } else if (p[win[i]] == 's' && p[win[i + 1]] == 'r') {
            win[j++] = win[i + 1];
        } else if (p[win[i]] == 'r' && p[win[i + 1]] == 'p') {
            win[j++] = win[i + 1];
        } else if (p[win[i]] == 'r' && p[win[i + 1]] == 's') {
            win[j++] = win[i];
        } else if (p[win[i]] == p[win[i + 1]]) {
            if (judge[cnt] == 'b') {
                win[j++] = win[i + 1];
            } else if (judge[cnt] == 's') {
                win[j++] = win[i];
            }
        }
        i++;
    }
    n /= 2;
    cnt += 1;
    if (n > 1) {
        who_win(n, cnt, p, judge, win);
    } else {
        printf("%d", win[0] + 1);
    }
}
