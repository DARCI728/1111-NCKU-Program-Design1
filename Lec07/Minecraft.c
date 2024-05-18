#include <stdio.h>

void dismantling(int arr[10], int arr_c[10], int table[100][100]);

int main() {
    int N, qty, arr[10] = {0, 1, 0}, arr_c[10] = {0, 1, 0}, table[100][100];
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            table[i][j] = -1;
        }
    }
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &qty);
        if (qty == 0) {
            table[i][0] = 0;
        } else {
            for (int j = 0; j < qty; j++) {
                scanf("%d", &table[i][j]);
            }
        }
    }
    dismantling(arr, arr_c, table);
    printf("%d", arr_c[0]);
    return 0;
}

void dismantling(int arr[10], int arr_c[10], int table[100][100]) {
    if (table[arr[1]][0] == -1) {
        ;
    } else if (table[arr[1]][arr[2]] == -1) {
        arr_c[1]++;
        arr_c[2] = 0;
        for (int i = 0; i < 3; i++) {
            arr[i] = arr_c[i];
        }
        dismantling(arr, arr_c, table);
    } else if (table[arr[1]][arr[2]] == 0) {
        arr_c[0]++;
        arr_c[2]++;
        for (int i = 0; i < 3; i++) {
            arr[i] = arr_c[i];
        }
        dismantling(arr, arr_c, table);
    } else {
        for (int i = 0; i < 20; i++) {
            int n_arr[3] = {arr_c[0], table[arr[1]][arr[2]], i};
            if (table[table[arr[1]][arr[2]]][i] == -1) {
                break;
            }
            dismantling(n_arr, arr_c, table);
        }
    }
}