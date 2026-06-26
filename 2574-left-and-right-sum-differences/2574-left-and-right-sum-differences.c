/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* leftRightDifference(int* nums, int numsSize, int* returnSize) {
    int *ans=(int *)malloc(numsSize*sizeof(int));
    *returnSize=numsSize;
    int leftsum=0;
    for (int i=0;i<numsSize;i++){
        ans[i]=leftsum;
        leftsum+=nums[i];
    }
    int rightsum=0;
    for (int i=numsSize-1;i>=0;i--){
        ans[i]=abs(ans[i]-rightsum);
        rightsum+=nums[i];
    }
    return ans;
}