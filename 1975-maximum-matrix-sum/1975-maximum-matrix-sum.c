long long maxMatrixSum(int** matrix, int matrixSize, int* matrixColSize) {
    long long sum=0;
    int neg=0;
    int min=2147483647;
    for(int i=0;i<matrixSize;i++){
        for(int j=0;j<matrixColSize[i];j++){
            int x=matrix[i][j];
            if(x<0){
                neg++;
            }
            if(x<0){
                x=-x;
            }
            sum+=x;
            if(x<min){
                min=x;
            }
        }
    }
    if(neg%2==1){
        sum-=2LL*min;
    }
    return sum;
}