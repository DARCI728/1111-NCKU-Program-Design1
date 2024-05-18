#include <stdio.h>
#include <string.h>

#define max_len 4096

int main() {
    int d, h, win, legal = 0, round = 1, cnt = 0;
    char command_t[4096], command[4096];
    scanf("%d%d\n", &d, &h);
    fgets(command_t, max_len, stdin);
    for (int i = 0; i < max_len; i++) {
        if (command_t[i] == '.' || command_t[i] == ',') command_t[i] = '\n';
    }
    for (int i = 0; i < max_len; i++) {
        command[cnt++] = command_t[i];
        if (command_t[i] == '\n') {
            if (strncmp(command, "PATA PATA PATA PON", 18) == 0) {
                legal++;
                if (round == 10 || round == 20) {
                    win = -1;
                    break;
                }
                if (--d == 0) {
                    win = -1;
                    break;
                }
            } else if (strncmp(command, "PON PON PATA PON", 16) == 0) {
                legal++;
                if (d <= 3) {
                    if (--h == 0) {
                        win = 1;
                        break;
                    }
                }
                if (round == 10 || round == 20) {
                    win = -1;
                    break;
                }
            } else if (strncmp(command, "CHAKA CHAKA PATA PON", 20) == 0) {
                legal++;
                d++;
            }
            char command[max_len];
            cnt = 0;
            round++;
        }
    }
    if (win == 1) {
        printf("YES %d", legal);
    } else {
        printf("NO %d", h);
    }
    return 0;
}
