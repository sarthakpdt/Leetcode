int countSubmatrices(int** grid, int gridSize, int* gridColSize, int k) {
    int m = gridSize;
    int n = gridColSize[0];
    
    long long prefix[m][n];
    int count = 0;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            
            prefix[i][j] = grid[i][j];

            if(i > 0)
                prefix[i][j] += prefix[i-1][j];

            if(j > 0)
                prefix[i][j] += prefix[i][j-1];

            if(i > 0 && j > 0)
                prefix[i][j] -= prefix[i-1][j-1];

            // check condition
            if(prefix[i][j] <= k){
                count++;
            }
        }
    }

    return count;
}