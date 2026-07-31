int longestAlternatingSubarray(int* nums,int numsSize,int threshold){
    int max=0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]%2!=0 || nums[i]>threshold){
            continue;
        }
        int curr=1;
        for(int j=i+1;j<numsSize;j++){
            if(nums[j]>threshold){
                break;
            }
            if((nums[j]%2)==(nums[j-1]%2)){
                break;
            }
            curr++;
            if(max<curr){
                max=curr;
            }
        }
        if(max<curr){
            max=curr;
        }
    }
    return max;
}