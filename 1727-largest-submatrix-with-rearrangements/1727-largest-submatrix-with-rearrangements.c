int c(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int largestSubmatrix(int** m, int s, int* z) {
    int r=s, l=z[0], a=0;
    for (int i=1; i<r; i++) {
        for (int j=0; j<l; j++) {
            if (m[i][j]==1) {
                m[i][j]+=m[i-1][j];
            }
        }
    }

    for (int i=0; i<r; i++) {
        qsort(m[i], l, sizeof(int), c);
        for (int j=0; j<l; j++) {
            int t=m[i][j]*(j+1);
            if (t>a) a=t;
        }
    }

    return a;
}