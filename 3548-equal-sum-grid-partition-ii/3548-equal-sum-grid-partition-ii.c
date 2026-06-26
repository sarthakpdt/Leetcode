typedef struct {
    int* counts;
} FreqMap;

bool can_remove(int** grid, int r1, int r2, int c1, int c2, long long diff, FreqMap* total, FreqMap* current, bool is_current) {
    if (diff <= 0 || diff > 100000) return false;
    
    int rows = r2 - r1 + 1;
    int cols = c2 - c1 + 1;
    if (rows * cols <= 1) return false; // Must remain non-empty

    // 1D Case: Only end cells
    if (rows == 1) return (grid[r1][c1] == diff || grid[r1][c2] == diff);
    if (cols == 1) return (grid[r1][c1] == diff || grid[r2][c1] == diff);

    // 2D Case: Any cell in the section can be removed
    if (is_current) return current->counts[diff] > 0;
    return (total->counts[diff] - current->counts[diff]) > 0;
}

bool canPartitionGrid(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = gridColSize[0];
    long long totalSum = 0;
    FreqMap total = { .counts = (int*)calloc(100001, sizeof(int)) };
    long long* rowSums = (long long*)malloc(m * sizeof(long long));
    long long* colSums = (long long*)calloc(n, sizeof(long long));

    for (int i = 0; i < m; i++) {
        rowSums[i] = 0;
        for (int j = 0; j < n; j++) {
            rowSums[i] += grid[i][j];
            colSums[j] += grid[i][j];
            total.counts[grid[i][j]]++;
            totalSum += grid[i][j];
        }
    }

    // 1. Horizontal Cuts
    FreqMap topFreq = { .counts = (int*)calloc(100001, sizeof(int)) };
    long long topSum = 0;
    for (int i = 0; i < m - 1; i++) {
        topSum += rowSums[i];
        for (int j = 0; j < n; j++) topFreq.counts[grid[i][j]]++;
        long long botSum = totalSum - topSum;
        if (topSum == botSum || 
            can_remove(grid, 0, i, 0, n - 1, topSum - botSum, &total, &topFreq, true) ||
            can_remove(grid, i + 1, m - 1, 0, n - 1, botSum - topSum, &total, &topFreq, false)) {
            goto success;
        }
    }

    // 2. Vertical Cuts
    FreqMap leftFreq = { .counts = (int*)calloc(100001, sizeof(int)) };
    long long leftSum = 0;
    for (int j = 0; j < n - 1; j++) {
        leftSum += colSums[j];
        for (int i = 0; i < m; i++) leftFreq.counts[grid[i][j]]++;
        long long rightSum = totalSum - leftSum;
        if (leftSum == rightSum || 
            can_remove(grid, 0, m - 1, 0, j, leftSum - rightSum, &total, &leftFreq, true) ||
            can_remove(grid, 0, m - 1, j + 1, n - 1, rightSum - leftSum, &total, &leftFreq, false)) {
            free(leftFreq.counts); goto success;
        }
    }

    free(total.counts); free(topFreq.counts); free(leftFreq.counts);
    free(rowSums); free(colSums);
    return false;

success:
    free(total.counts); free(topFreq.counts);
    free(rowSums); free(colSums);
    return true;
}