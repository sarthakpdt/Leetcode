/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findThePrefixCommonArray(int* A, int ASize, int* B, int BSize, int* returnSize) {
    *returnSize=ASize;
    int *arr=(int *)malloc(ASize*sizeof(int));
    int *fre=(int *)calloc(ASize+1,sizeof(int));
    int count=0;
    for (int i=0;i<ASize;i++){
        fre[A[i]]++;
        if (fre[A[i]]==2){
            count++;
        }
        fre[B[i]]++;
        if (fre[B[i]]==2){
            count++;
        }
        arr[i]=count;
    }
    free(fre);
    return arr;
}