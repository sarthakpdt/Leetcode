/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int compare(const void *a,const void *b){
    return (*(int *)a-*(int *)b);
}
void backtrack(int index,int sum,int target,int *candidates,int candidatesSize,int *curr,int currSize,int **res,int *returnSize,int *columnSizes){
    if(sum==target){
        res[*returnSize]=(int *)malloc(currSize*sizeof(int));
        for(int i=0;i<currSize;i++){
            res[*returnSize][i]=curr[i];
        }
        columnSizes[*returnSize]=currSize;
        (*returnSize)++;
        return;
    }
    for(int i=index;i<candidatesSize;i++){
        if(sum+candidates[i]>target){
            break;
        }
        if(i>index && candidates[i]==candidates[i-1]){
            continue;
        }
        curr[currSize]=candidates[i];
        backtrack(i+1,sum+candidates[i],target,candidates,candidatesSize,curr,currSize+1,res,returnSize,columnSizes);
    }
}
int** combinationSum2(int* candidates,int candidatesSize,int target,int* returnSize,int** returnColumnSizes){
    qsort(candidates,candidatesSize,sizeof(int),compare);
    int **res=(int **)malloc(200*sizeof(int *));
    *returnColumnSizes=(int *)malloc(200*sizeof(int));
    int curr[candidatesSize];
    *returnSize=0;
    backtrack(0,0,target,candidates,candidatesSize,curr,0,res,returnSize,*returnColumnSizes);
    return res;
}