int countMajoritySubarrays(int* nums, int numsSize, int target) {
    int ans=0;
    for (int i=0;i<numsSize;i++){
        int count=0;
        for (int j=i;j<numsSize;j++){
            count+=(nums[j]==target?1:-1);
            if (count>0){
                ans++;
            }
        }
    }
    return ans;
}