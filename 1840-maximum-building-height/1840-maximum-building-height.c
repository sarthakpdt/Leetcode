int cmp(const void* a, const void* b) {
    int* pa = *(int**)a;
    int* pb = *(int**)b;
    return pa[0] - pb[0];
}

int maxBuilding(int n, int** restrictions, int restrictionsSize,
                int* restrictionsColSize) {
    int m = restrictionsSize + 2;
    int** r = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        r[i] = (int*)malloc(2 * sizeof(int));
    }
    for (int i = 0; i < restrictionsSize; i++) {
        r[i][0] = restrictions[i][0];
        r[i][1] = restrictions[i][1];
    }

    // Add restriction (1, 0)
    r[restrictionsSize][0] = 1;
    r[restrictionsSize][1] = 0;
    int currentSize = restrictionsSize + 1;
    // Sorting
    qsort(r, currentSize, sizeof(int*), cmp);

    // Add restriction (n, n-1)
    if (r[currentSize - 1][0] != n) {
        r[currentSize][0] = n;
        r[currentSize][1] = n - 1;
        currentSize++;
    }

    // Pass restrictions from left to right
    for (int i = 1; i < currentSize; ++i) {
        int dist = r[i][0] - r[i - 1][0];
        int val = r[i - 1][1] + dist;
        if (val < r[i][1]) {
            r[i][1] = val;
        }
    }

    // Pass restrictions from right to left
    for (int i = currentSize - 2; i >= 0; --i) {
        int dist = r[i + 1][0] - r[i][0];
        int val = r[i + 1][1] + dist;
        if (val < r[i][1]) {
            r[i][1] = val;
        }
    }

    int ans = 0;
    for (int i = 0; i < currentSize - 1; ++i) {
        int dist = r[i + 1][0] - r[i][0];
        int best = (dist + r[i][1] + r[i + 1][1]) / 2;
        if (best > ans) {
            ans = best;
        }
    }
    for (int i = 0; i < currentSize; i++) {
        free(r[i]);
    }
    free(r);

    return ans;
}