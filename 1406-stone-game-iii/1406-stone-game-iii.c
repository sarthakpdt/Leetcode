int max(int a,int b){
    return (a>b)?a:b;
}
char* stoneGameIII(int* stoneValue,int stoneValueSize){
    int n=stoneValueSize;
    int dp[n+3];
    dp[n]=0;
    dp[n+1]=0;
    dp[n+2]=0;
    for(int i=n-1;i>=0;i--){
        int sum=0;
        dp[i]=-1000000000;
        for(int k=0;k<3&&i+k<n;k++){
            sum+=stoneValue[i+k];
            dp[i]=max(dp[i],sum-dp[i+k+1]);
        }
    }
    if(dp[0]>0){
        return "Alice";
    }
    else if(dp[0]<0){
        return "Bob";
    }
    else{
        return "Tie";
    }
}