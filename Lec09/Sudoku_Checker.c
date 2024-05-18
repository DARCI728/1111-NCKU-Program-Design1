#include <stdio.h>
#define NUM 9

void check_sudoku(int (*grid_p)[NUM]);

int main(void) {
    int grid[NUM][NUM];  // sudoku puzzle
    for (int i = 0; i < NUM; ++i) {
        for (int j = 0; j < NUM; ++j) {
            scanf("%d", &grid[i][j]);
        }
    }
    check_sudoku(grid);
    return 0;
}

void check_sudoku(int (*grid_p)[NUM]) {
    int ans[NUM][NUM] = {0};
    for (int i = 0; i < NUM; i++) {
        int arr_c[10] = {0}, arr_r[10] = {0};
        for (int j = 0; j < NUM; j++) {
            // each column
            if (arr_c[grid_p[i][j]] == -1) {
                for (int k = 0; k < NUM; k++) {
                    if (grid_p[i][k] == grid_p[i][j])
                        ans[i][k] = -1;
                }
            } else {
                arr_c[grid_p[i][j]] = -1;
            }
            // each row
            if (arr_r[grid_p[j][i]] == -1) {
                for (int k = 0; k < NUM; k++) {
                    if (grid_p[k][i] == grid_p[j][i])
                        ans[k][i] = -1;
                }
            } else {
                arr_r[grid_p[j][i]] = -1;
            }
        }
    }
    // each of the nine 3×3 subgrids
    int plus[9] = {0, 1, 2, 9, 10, 11, 18, 19, 20};
    int start[9] = {0, 3, 6, 27, 30, 33, 54, 57, 60};
    for (int i = 0; i < NUM; i++) {
        int arr[10] = {0};
        for (int j = 0; j < NUM; j++) {
            if (arr[(*grid_p)[start[i] + plus[j]]] == -1) {
                for (int k = 0; k < NUM; k++) {
                    if ((*grid_p)[start[i] + plus[k]] == (*grid_p)[start[i] + plus[j]]) {
                        (*ans)[start[i] + plus[k]] = -1;
                    }
                }
            } else {
                arr[(*grid_p)[start[i] + plus[j]]] = -1;
            }
        }
    }
    // print
    for (int i = 0; i < NUM; i++) {
        for (int j = 0; j < NUM; j++)
            if (*(ans[i] + j) == -1) printf("(%d,%d)\n", i, j);
    }
}
