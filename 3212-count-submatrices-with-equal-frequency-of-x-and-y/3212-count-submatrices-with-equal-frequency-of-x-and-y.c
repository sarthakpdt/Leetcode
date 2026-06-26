int numberOfSubmatrices(char** grid, int gridSize, int* gridColSize) {
    int rows = gridSize;
    int cols = gridColSize[0];
    int count = 0;
    int** diff = (int**)malloc(rows * sizeof(int*));
    int** hasX = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        diff[i] = (int*)calloc(cols, sizeof(int));
        hasX[i] = (int*)calloc(cols, sizeof(int));
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int d = (grid[i][j] == 'X') ? 1 : (grid[i][j] == 'Y' ? -1 : 0);
            int x = (grid[i][j] == 'X') ? 1 : 0;
            if (i > 0) {
                d += diff[i - 1][j];
                x += hasX[i - 1][j];
            }
            if (j > 0) {
                d += diff[i][j - 1];
                x += hasX[i][j - 1];
            }
            if (i > 0 && j > 0) {
                d -= diff[i - 1][j - 1];
                x -= hasX[i - 1][j - 1];
            }
            diff[i][j] = d;
            hasX[i][j] = x;
            if (diff[i][j] == 0 && hasX[i][j] > 0) {
                count++;
            }
        }
    }
    for (int i = 0; i < rows; i++) {
        free(diff[i]);
        free(hasX[i]);
    }
    free(diff);
    free(hasX);
    return count;
}