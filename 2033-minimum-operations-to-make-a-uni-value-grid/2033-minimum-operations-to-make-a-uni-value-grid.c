int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minOperations(int** grid, int gridSize, int* gridColSize, int x) {
    int m = gridSize;
    int n = gridColSize[0];
    int totalElements = m * n;
    
    // Flatten the 2D grid into a 1D array for sorting
    int* flat = (int*)malloc(totalElements * sizeof(int));
    int modValue = grid[0][0] % x;
    int k = 0;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // If remainders differ, it's impossible to make elements equal
            if (grid[i][j] % x != modValue) {
                free(flat);
                return -1;
            }
            flat[k++] = grid[i][j];
        }
    }
    
    // Sort to find the median
    qsort(flat, totalElements, sizeof(int), compare);
    
    int median = flat[totalElements / 2];
    int operations = 0;
    
    for (int i = 0; i < totalElements; i++) {
        // Number of operations to change flat[i] to median
        operations += abs(flat[i] - median) / x;
    }
    
    free(flat);
    return operations;
}