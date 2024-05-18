#include <stdio.h>
#include <string.h>

#define SIZE 25

int length(char pwd1[], char pwd2[]);

int compare(char pwd1[], char pwd2[]);

int content(char pwd1[]);

int main() {
    char password1[SIZE];
    char password2[SIZE];

    // Enter the password
    scanf("%s", password1);
    // Enter the password again
    scanf("%s", password2);

    // Check Password
    // First: Check length
    if (length(password1, password2) == 1) {
        printf("Length does not match the requirements");
    } else {
        // Second: Check for consistency
        if (compare(password1, password2) == 1) {
            printf("Not the same password");
        } else {
            // Third: Check for compliance
            if (content(password1) == 1) {
                printf("Do not satisfy the conditions");
            } else {
                printf("Everything is good");
            }
        }
    }

    return 0;
}

int length(char pwd1[], char pwd2[]) {
    if (strlen(pwd1) < 6 || strlen(pwd1) > 16 || strlen(pwd2) < 6 || strlen(pwd2) > 16) {
        return 1;
    } else {
        return 0;
    }
}

int compare(char pwd1[], char pwd2[]) {
    if (strlen(pwd1) != strlen(pwd2)) {
        return 1;
    } else {
        for (int i = 0; i < strlen(pwd1); i++) {
            if (pwd1[i] != pwd2[i]) {
                return 1;
            }
        }
    }
    return 0;
}

int content(char pwd1[]) {
    int cheak1 = 0, cheak2 = 0, cheak3 = 0;
    for (int i = 0; i < strlen(pwd1); i++) {
        if ('A' <= pwd1[i] && pwd1[i] <= 'Z') cheak1++;
        if ('a' <= pwd1[i] && pwd1[i] <= 'z') cheak2++;
        if ('0' <= pwd1[i] && pwd1[i] <= '9') cheak3++;
    }
    if (cheak1 > 0 && cheak2 > 0 && cheak3 > 0) {
        return 0;
    } else {
        return 1;
    }
}