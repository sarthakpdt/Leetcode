int minElement(int* nums, int numsSize) {
    int i=0;
    while(i<numsSize){
        int b=0;
        int temp=nums[i];
        while(temp>0){
            int a=temp%10;
            b=b+a;
            temp=temp/10;
        }
        nums[i]=b;
        i++;
    }
    int min=nums[0];
    int j=1;
    while(j<numsSize){
        if (nums[j]<min){
            min=nums[j];
        }
        j++;
    }
    return min;
}