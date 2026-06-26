int minimumDistance(int* nums, int numsSize) {
    int min=INT_MAX;
    int found=0;
    for (int i=0;i<numsSize;i++){
        for (int j=i+1;j<numsSize;j++){
            for (int k=j+1;k<numsSize;k++){
                if ((nums[i]==nums[j]) && (nums[j]==nums[k])){
                    int dis=abs(i-j)+abs(j-k)+abs(i-k);
                    if (dis<min){
                        min=dis;
                    }
                    found=1;
                }
            }
        }
    }
    return (found)?min:-1;
}