int getMinDistance(int* nums, int numsSize, int target, int start) {
    int min=numsSize;
    for (int i=0;i<numsSize;i++){
        if (nums[i]==target){
            int d=(abs(i-start));
            if (d<min){
                min=d;
            }
        }
    }
    return min;
}