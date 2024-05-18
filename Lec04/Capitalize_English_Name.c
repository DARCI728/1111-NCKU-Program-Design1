#include <stdio.h>
#include <string.h>

int main() {
    int n, len, count = 0;
    char name[100];
    scanf("%d", &n);
    while (1) {
        if (count < n) {
            scanf("%s", name);
            len = strlen(name);
        } else {
            break;
        }
        for (int i = 0; i < len; i++) {
            if ('A' <= name[i] && name[i] <= 'Z') {
                name[i] += 32;
            }
        }
        for (int i = 0; i < len; i++) {
            if ('a' <= name[0] && name[0] <= 'z') {
                name[0] -= 32;
            }
            if (name[i] == ',' || name[i] == '.' || name[i] == ';') {
                name[i + 1] -= 32;
                name[i] = '\n';
                count += 1;
            }
            printf("%c", name[i]);
        }
        printf(" ");
    }
    return 0;
}
