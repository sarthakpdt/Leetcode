int uniqueXorTriplets(int* nums,int numsSize){
    bool dp[4][2048];
    memset(dp,false,sizeof(dp));
    dp[0][0]=true;
    for(int t=0;t<3;t++){
        for(int i=0;i<numsSize;i++){
            for(int x=0;x<2048;x++){
                if(dp[t][x]){
                    dp[t+1][x^nums[i]]=true;
                }
            }
        }
    }
    int count=0;
    for(int x=0;x<2048;x++){
        if(dp[3][x]){
            count++;
        }
    }
    return count;
}