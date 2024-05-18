#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_LEN 20

void recovery(char *homework);

int main() {
    char homework[MAX_LEN + 1];
    fgets(homework, MAX_LEN, stdin);
    recovery(homework);
    fputs(homework, stdout);
    return 0;
}

void recovery(char *homework) {
    int i, j, l_index = 0, r_index, delete, len = strlen(homework);
    for (i = 0; i < MAX_LEN; i++) {
        if (*(homework + i) == ' ' || *(homework + i) == '\n' || *(homework + i) == '\0') {
            r_index = i + 1;
            break;
        }
    }
    while (1) {
        if (r_index - l_index - 1 > 21) delete = 1;
        for (i = l_index; i < r_index - 1; i++) {
            if (isalpha((int)*(homework + i))) {
                ;
            } else {
                if (*(homework + i) != '.' && *(homework + i) != ',' && *(homework + i) != '!' && *(homework + i) != '?') {
                    delete = 1;
                } else if (isalpha((int)*(homework + i - 1)) == 0 || *(homework + i - 1) == ' ') {
                    delete = 1;
                } else if (*(homework + i + 1) != ' ' && *(homework + i + 1) != '\n') {
                    delete = 1;
                }
            }
        }
        if (delete == 1) {
            for (j = 0; j < len; j++) {
                *(homework + l_index + j) = *(homework + r_index + j);
                if (*(homework + l_index + j) == '\0') {
                    *(homework + l_index + j) = '\n';
                    *(homework + l_index + j + 1) = '\0';
                    break;
                }
            }
            delete = 0;
        } else {
            l_index = r_index;
        }
        for (i = l_index; i < len; i++) {
            if (*(homework + i) == ' ' || *(homework + i) == '\n') {
                r_index = i + 1;
                break;
            }
        }
        if (*(homework + l_index) == '\0') break;
    }
}