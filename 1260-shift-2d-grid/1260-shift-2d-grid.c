/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** shiftGrid(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes) {
    int m=gridSize;
    int n=gridColSize[0];
    int **temp=(int **)malloc(sizeof(int *)*gridSize);
    for (int i=0;i<m;i++){
        temp[i]=(int *)malloc(sizeof(int)*n);
    }
    int l=0;
    while(l<k){
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (i==m-1 && j==n-1){
                    temp[0][0]=grid[i][j];
                }
                else if(j==n-1){
                    temp[i+1][0]=grid[i][j];
                }
                else{
                    temp[i][j+1]=grid[i][j];
                }
            }
        }
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                grid[i][j]=temp[i][j];
            }
        }
        l++;
    }
    *returnSize=m;
    *returnColumnSizes=(int *)malloc(sizeof(int)*m);
    for (int i=0;i<m;i++){
        (*returnColumnSizes)[i]=n;
    }
    return grid;
}