int** constructProductMatrix(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
    int n = gridSize;
    int m = gridColSize[0];
    long long totalElements = (long long)n * m;
    int MOD = 12345;

    // Allocate return structures
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    int** p = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        (*returnColumnSizes)[i] = m;
        p[i] = (int*)malloc(m * sizeof(int));
    }

    // Step 1: Forward pass (Prefix Products)
    long long prefix = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            p[i][j] = (int)prefix;
            prefix = (prefix * (grid[i][j] % MOD)) % MOD;
        }
    }

    // Step 2: Backward pass (Suffix Products)
    long long suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            p[i][j] = (int)((p[i][j] * suffix) % MOD);
            suffix = (suffix * (grid[i][j] % MOD)) % MOD;
        }
    }

    return p;
}