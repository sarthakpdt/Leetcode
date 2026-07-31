/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int compare(const void *a,const void *b){
    return (*(int *)a-*(int *)b);
}
void backtrack(int index,int *nums,int numsSize,int *curr,int currSize,int **res,int *returnSize,int *columnSizes){
    res[*returnSize]=(int *)malloc(currSize*sizeof(int));
    for(int i=0;i<currSize;i++){
        res[*returnSize][i]=curr[i];
    }
    columnSizes[*returnSize]=currSize;
    (*returnSize)++;
    for(int i=index;i<numsSize;i++){
        if(i>index && nums[i]==nums[i-1]){
            continue;
        }
        curr[currSize]=nums[i];
        backtrack(i+1,nums,numsSize,curr,currSize+1,res,returnSize,columnSizes);
    }
}
int** subsetsWithDup(int* nums,int numsSize,int* returnSize,int** returnColumnSizes){
    qsort(nums,numsSize,sizeof(int),compare);
    int **res=(int **)malloc(5000*sizeof(int *));
    *returnColumnSizes=(int *)malloc(5000*sizeof(int));
    int curr[numsSize];
    *returnSize=0;
    backtrack(0,nums,numsSize,curr,0,res,returnSize,*returnColumnSizes);
    return res;
}