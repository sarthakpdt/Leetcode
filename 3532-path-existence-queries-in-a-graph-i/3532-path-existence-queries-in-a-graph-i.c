/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* pathExistenceQueries(int n, int* nums, int numsSize, int maxDiff, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int *comp=(int *)malloc(n*sizeof(int));
    comp[0]=0;
    for (int i=1;i<n;i++){
        if (nums[i]-nums[i-1]<=maxDiff){
            comp[i]=comp[i-1];
        }
        else{
            comp[i]=comp[i-1]+1;
        }
    }
    bool *ans=(bool *)malloc(queriesSize*sizeof(bool));
    for (int i=0;i<queriesSize;i++){
        int u=queries[i][0];
        int v=queries[i][1];
        if (comp[u]==comp[v]){
            ans[i]=1;
        }
        else{
            ans[i]=0;
        }
    }
    *returnSize=queriesSize;
    return ans;
}