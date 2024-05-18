#include <stdio.h>
#include <string.h>

int main() {
    double count = 0, n, sum;
    char grades[100];
    fgets(grades, 100, stdin);
    for (int i = 0; i < strlen(grades); i++) {
        if ('0' <= grades[i] && grades[i] <= '9') {
            n = grades[i] - '0';
            count += grades[i] - '0';
        } else if (('A' <= grades[i] && grades[i] <= 'Z') && grades[i + 1] == '+') {
            if (grades[i] == 'A') {
                sum += n * 4.3;
                i++;
            } else if (grades[i] == 'B') {
                sum += n * 3.3;
                i++;
            } else {
                sum += n * 2.3;
                i++;
            }
        } else if (('A' <= grades[i] && grades[i] <= 'Z') && grades[i + 1] == '-') {
            if (grades[i] == 'A') {
                sum += n * 3.7;
                i++;
            } else if (grades[i] == 'B') {
                sum += n * 2.7;
                i++;
            } else {
                sum += n * 1.7;
                i++;
            }
        } else {
            if (grades[i] == 'A') {
                sum += n * 4.0;
            } else if (grades[i] == 'B') {
                sum += n * 3.0;
            } else if (grades[i] == 'C') {
                sum += n * 2.0;
            }
        }
    }
    printf("%.2f", sum / count);
    return 0;
}
