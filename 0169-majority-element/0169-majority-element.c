int majorityElement(int* nums, int numsSize) {
    int count=0;
    int can=0;
    for (int i=0;i<numsSize;i++){
        if (count==0){
            can=nums[i];
        }
        if (nums[i]==can){
            count++;
        }
        else{
            count--;
        }
    }
    return can;
}