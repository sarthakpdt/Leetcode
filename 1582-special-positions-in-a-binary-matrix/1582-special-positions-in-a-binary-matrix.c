int numSpecial(int** mat, int matSize, int* matColSize) {
    int row=matSize;
    int col=matColSize[0];
    int rowsum[row];
    int colsum[col];
    int count=0;
    for (int i=0;i<row;i++){
        rowsum[i]=0;
    }
    for (int j=0;j<col;j++){
        colsum[j]=0;
    }
    for (int i=0;i<row;i++){
        for (int j=0;j<col;j++){
            if (mat[i][j]==1){
                rowsum[i]++;
                colsum[j]++;
            }
        }
    }
    for (int i=0;i<row;i++){
        for (int j=0;j<col;j++){
            if (mat[i][j]==1 && rowsum[i]==1 && colsum[j]==1){
                count++;
            }
        }
    }
    return count;
}