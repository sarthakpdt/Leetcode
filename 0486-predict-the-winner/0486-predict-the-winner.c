int solve(int *nums,int left,int right){
    if(left==right){
        return nums[left];
    }
    int pickLeft=nums[left]-solve(nums,left+1,right);
    int pickRight=nums[right]-solve(nums,left,right-1);
    if(pickLeft>pickRight){
        return pickLeft;
    }
    return pickRight;
}
bool predictTheWinner(int* nums,int numsSize){
    if(solve(nums,0,numsSize-1)>=0){
        return true;
    }
    return false;
}