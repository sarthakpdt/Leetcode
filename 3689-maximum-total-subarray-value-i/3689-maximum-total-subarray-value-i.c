long long maxTotalValue(int* nums, int numsSize, int k) {
    int max=nums[0];
    int min=nums[0];
    if (numsSize<=0){
        return 0;
    }
    for (int i=1;i<numsSize;i++){
        if (nums[i]>max){
            max=nums[i];
        }
        if (nums[i]<min){
            min=nums[i];
        }
    }
    long long value=max-min;
    long long a=k*value;
    return a;
}