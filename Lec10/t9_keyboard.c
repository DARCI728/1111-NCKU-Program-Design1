#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_LEN 1024
#define LINE_LEN 128

void convert(char *arr[], int count);

int main() {
    char line[BUFFER_LEN];
    char buffer[LINE_LEN][BUFFER_LEN];
    char *arr[LINE_LEN];

    int count = 0;
    while (fgets(line, BUFFER_LEN - 1, stdin) != NULL) {
        arr[count] = buffer[count];
        strncpy(buffer[count++], line, BUFFER_LEN - 1);
    }
    convert(arr, count);
    for (int i = 0; i < count; i++) {
        printf("%s", arr[i]);
    }
}

void convert(char *arr[], int count) {
    char ans[LINE_LEN][BUFFER_LEN];
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < LINE_LEN; j++) {
            if (arr[i][j] == '\0')
                break;
            else if (arr[i][j] == 'a')
                strcat(ans[i], "(2)1");
            else if (arr[i][j] == 'b')
                strcat(ans[i], "(2)2");
            else if (arr[i][j] == 'c')
                strcat(ans[i], "(2)3");
            else if (arr[i][j] == 'd')
                strcat(ans[i], "(3)1");
            else if (arr[i][j] == 'e')
                strcat(ans[i], "(3)2");
            else if (arr[i][j] == 'f')
                strcat(ans[i], "(3)3");
            else if (arr[i][j] == 'g')
                strcat(ans[i], "(4)1");
            else if (arr[i][j] == 'h')
                strcat(ans[i], "(4)2");
            else if (arr[i][j] == 'i')
                strcat(ans[i], "(4)3");
            else if (arr[i][j] == 'j')
                strcat(ans[i], "(5)1");
            else if (arr[i][j] == 'k')
                strcat(ans[i], "(5)2");
            else if (arr[i][j] == 'l')
                strcat(ans[i], "(5)3");
            else if (arr[i][j] == 'm')
                strcat(ans[i], "(6)1");
            else if (arr[i][j] == 'n')
                strcat(ans[i], "(6)2");
            else if (arr[i][j] == 'o')
                strcat(ans[i], "(6)3");
            else if (arr[i][j] == 'p')
                strcat(ans[i], "(7)1");
            else if (arr[i][j] == 'q')
                strcat(ans[i], "(7)2");
            else if (arr[i][j] == 'r')
                strcat(ans[i], "(7)3");
            else if (arr[i][j] == 's')
                strcat(ans[i], "(7)4");
            else if (arr[i][j] == 't')
                strcat(ans[i], "(8)1");
            else if (arr[i][j] == 'u')
                strcat(ans[i], "(8)2");
            else if (arr[i][j] == 'v')
                strcat(ans[i], "(8)3");
            else if (arr[i][j] == 'w')
                strcat(ans[i], "(9)1");
            else if (arr[i][j] == 'x')
                strcat(ans[i], "(9)2");
            else if (arr[i][j] == 'y')
                strcat(ans[i], "(9)3");
            else if (arr[i][j] == 'z')
                strcat(ans[i], "(9)4");
            else if (arr[i][j] == ' ')
                strcat(ans[i], " ");
            else if (arr[i][j] == '\n')
                strcat(ans[i], "\n");
        }
    }
    for (int i = 0; i < count; i++) {
        strcpy(arr[i], ans[i]);
    }
}
