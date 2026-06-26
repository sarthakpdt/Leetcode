int compare(const void* a, const void* b) {
    return (*(const int*)a - *(const int*)b);
}

int** minAbsDiff(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes) {
    int m = gridSize, n = gridColSize[0];
    int resRows = m - k + 1, resCols = n - k + 1;

    *returnSize = resRows;
    *returnColumnSizes = (int*)malloc(resRows * sizeof(int));
    int** ans = (int**)malloc(resRows * sizeof(int*));
    int* temp = (int*)malloc(k * k * sizeof(int));

    for (int i = 0; i < resRows; i++) {
        ans[i] = (int*)malloc(resCols * sizeof(int));
        (*returnColumnSizes)[i] = resCols;

        for (int j = 0; j < resCols; j++) {
            int idx = 0;
            for (int r = i; r < i + k; r++) {
                for (int c = j; c < j + k; c++) {
                    temp[idx++] = grid[r][c];
                }
            }

            qsort(temp, k * k, sizeof(int), compare);

            int minDiff = INT_MAX;
            int foundDistinctPair = 0;

            for (int x = 0; x < k * k - 1; x++) {
                // Only calculate difference if the values are distinct
                if (temp[x] != temp[x+1]) {
                    int diff = temp[x+1] - temp[x];
                    if (diff < minDiff) minDiff = diff;
                    foundDistinctPair = 1;
                }
            }

            // If no distinct pairs were found (all elements same), result is 0
            ans[i][j] = (foundDistinctPair) ? minDiff : 0;
        }
    }
    free(temp);
    return ans;
}