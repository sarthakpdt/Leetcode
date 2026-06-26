bool canPartitionGrid(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    long long totalSum = 0;

    // Calculate total sum of the entire grid
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            totalSum += grid[i][j];
        }
    }

    // If the sum is odd, it cannot be split into two equal integer parts
    if (totalSum % 2 != 0) return false;
    long long target = totalSum / 2;

    // Check Horizontal Cuts (summing rows)
    long long rowPrefixSum = 0;
    for (int i = 0; i < m - 1; i++) { // m-1 to ensure the bottom section is non-empty
        for (int j = 0; j < n; j++) {
            rowPrefixSum += grid[i][j];
        }
        if (rowPrefixSum == target) return true;
    }

    // Check Vertical Cuts (summing columns)
    long long colPrefixSum = 0;
    for (int j = 0; j < n - 1; j++) { // n-1 to ensure the right section is non-empty
        for (int i = 0; i < m; i++) {
            colPrefixSum += grid[i][j];
        }
        if (colPrefixSum == target) return true;
    }

    return false;
}
