int maxSubarraySumCircular(int* nums,int numsSize){
    int currmax=0;
    int max=INT_MIN;
    int currmin=0;
    int min=INT_MAX;
    int total=0;
    for(int i=0;i<numsSize;i++){
        total+=nums[i];
        currmax+=nums[i];
        if(currmax>max){
            max=currmax;
        }
        if(currmax<0){
            currmax=0;
        }
        currmin+=nums[i];
        if(currmin<min){
            min=currmin;
        }
        if(currmin>0){
            currmin=0;
        }
    }
    if(max<0){
        return max;
    }
    int ans=total-min;
    if(max>ans){
        return max;
    }
    return ans;
}