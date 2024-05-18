#include <stdio.h>
#define ARR_MAX 1000

void sort_section(int *ptr, int *qtr);

int main() {
    int N, a, b;
    scanf("%d%d%d", &N, &a, &b);
    int arr[ARR_MAX] = {0};
    for (int i = 0; i < N; i++) {
        scanf("%d", arr + i);
    }
    sort_section(&arr[a], &arr[b]);
    for (int i = 0; i < N; i++) {
        printf("%d ", *(arr + i));
    }
    return 0;
}

void sort_section(int *ptr, int *qtr) {
    int len, temp, *a;
    if (qtr >= ptr) {
        len = qtr - ptr + 1;
    } else {
        a = ptr;
        ptr = qtr;
        qtr = a;
        len = qtr - ptr + 1;
    }
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (*(ptr + j) > *(ptr + j + 1)) {
                temp = *(ptr + j + 1);
                *(ptr + j + 1) = *(ptr + j);
                *(ptr + j) = temp;
            }
        }
        for (int i = 0; i < len; i++) {
            printf("%d ", *(ptr + i));
        }
        printf("\n");
    }
}