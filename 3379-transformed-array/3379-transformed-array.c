/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructTransformedArray(int* nums, int numsSize, int* returnSize) {
    int *res=(int*)malloc(numsSize*sizeof(int));
    for (int i=0;i<numsSize;i++){
        if (nums[i]>0){
            int newindex=(i+nums[i])%numsSize;
            res[i]=nums[newindex];
        }
        else if (nums[i]<0){
            int newindex=(i+(nums[i]%numsSize)+numsSize)%numsSize;
            if (newindex==numsSize) {
                newindex=-1;
            }
            res[i]=nums[newindex];
        }
        else{
            res[i]=0;
        }
    }
    *returnSize = numsSize;
    return res;
}