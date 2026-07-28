/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
long long* mergeAdjacent(int* nums, int numsSize, int* returnSize) {
    long long *stack=(long long *)malloc(sizeof(long long)*numsSize);
    int top=0;
    for (int i=0;i<numsSize;i++){
        stack[top++]=nums[i];
        while (top>=2 && stack[top-1]==stack[top-2]){
            stack[top-2]=stack[top-1]+stack[top-2];
            top--;
        }
    }
    *returnSize=top;
    return stack;
}