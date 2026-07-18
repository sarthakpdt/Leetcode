int findGCD(int* nums, int numsSize) {
    int max=nums[0];
    int min=nums[0];
    for(int i=1;i<numsSize;i++){
        int num=nums[i];
        if (num>max){
            max=num;
        }
        if (num<min){
            min=num;
        }
    }
    while(max!=0){
        int temp=max;
        max=min%max;
        min=temp;
    }
    return min;
}