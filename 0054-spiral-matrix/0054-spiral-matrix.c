/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    if(matrixSize==0){
        *returnSize=0;
        return NULL;
    }
    int rows=matrixSize;
    int cols=matrixColSize[0];
    int *res=(int *)malloc(sizeof(int)*rows*cols);
    int top=0;
    int bottom=rows-1;
    int left=0;
    int right=cols-1;
    int index=0;
    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++){
            res[index++]=matrix[top][i];
        }
        top++;
        for(int i=top;i<=bottom;i++){
            res[index++]=matrix[i][right];
        }
        right--;
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                res[index++]=matrix[bottom][i];
            }
            bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                res[index++]=matrix[i][left];
            }
            left++;
        }
    }
    *returnSize=index;
    return res;
}