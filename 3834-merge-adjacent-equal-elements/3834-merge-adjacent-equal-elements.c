/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
long long* mergeAdjacent(int* nums, int numsSize, int* returnSize) {
    long long *stack=(long long *)malloc(numsSize*sizeof(long long));
    int top=-1;
    for (int i=0;i<numsSize;i++){
        stack[++top]=nums[i];
        while (top>=1 && stack[top]==stack[top-1]){
            long long sum=stack[top]+stack[top-1];
            top-=2;
            stack[++top]=sum;
        }
    }
    *returnSize=top+1;
    return stack;
}