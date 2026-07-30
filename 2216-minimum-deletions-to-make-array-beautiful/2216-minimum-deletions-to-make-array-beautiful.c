int minDeletion(int* nums, int numsSize) {
    int *stack=(int *)malloc(sizeof(int)*numsSize);
    int top=0;
    int count=0;
    if (numsSize==0){
        return 0;
    }
    for(int i=0;i<numsSize;i++){
        stack[top++]=nums[i];
        if (top>=2 && stack[top-1]==stack[top-2] && top%2==0){
            top--;
            count++;
        }
    }
    if (top%2==1){
        count++;
    }
    return count;
}