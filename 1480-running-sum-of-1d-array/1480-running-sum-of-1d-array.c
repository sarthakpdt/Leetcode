

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize){
    int *runningSums=(int*)malloc(numsSize*sizeof(int));
    runningSums[0]=nums[0];
    for (int i=1;i<numsSize;i++){
        runningSums[i]=runningSums[i-1]+nums[i];
    }
    /*for (int i=0;i<numsSize;i++){
        printf("%d",runningSum[i]);
    }*/
    *returnSize=numsSize;
    return runningSums;
}