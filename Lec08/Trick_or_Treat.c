#include <stdio.h>
#include <stdlib.h>

int array[1500];
int maxChandy(int size);

int main() {
    int size = 0;
    scanf("%d", &size);
    for (int i = 0; i < size; ++i) {
        scanf("%d", &array[i]);
    }
    printf("%d", maxChandy(size));
    return 0;
}

int maxChandy(int size) {
    int max_sum[1500] = {array[0], array[1], array[0] + array[2]}, max_num1, max_num2;
    for (int i = 3; i < size; i++) {
        max_num1 = array[i] + max_sum[i - 2];
        max_num2 = array[i] + max_sum[i - 3];
        if (max_num1 > max_num2) {
            max_sum[i] = max_num1;
        } else {
            max_sum[i] = max_num2;
        }
    }
    if (max_sum[size - 1] > max_sum[size - 2]) {
        return max_sum[size - 1];
    } else {
        return max_sum[size - 2];
    }
}