#include <stdlib.h>

int** reverseSubmatrix(int** grid, int gridSize, int* gridColSize, int x, int y, int k, int* returnSize, int** returnColumnSizes) {
    int m = gridSize;
    int n = gridColSize[0];

    // Prepare return metadata
    *returnSize = m;
    *returnColumnSizes = (int*)malloc(m * sizeof(int));
    int** res = (int**)malloc(m * sizeof(int*));

    // Copy original grid to result matrix
    for (int i = 0; i < m; i++) {
        (*returnColumnSizes)[i] = n;
        res[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            res[i][j] = grid[i][j];
        }
    }

    // Perform vertical flip on the submatrix
    for (int i = 0; i < k / 2; i++) {
        int row1 = x + i;
        int row2 = x + k - 1 - i;

        for (int j = 0; j < k; j++) {
            int col = y + j;
            // Swap elements at (row1, col) and (row2, col)
            int temp = res[row1][col];
            res[row1][col] = res[row2][col];
            res[row2][col] = temp;
        }
    }

    return res;
}