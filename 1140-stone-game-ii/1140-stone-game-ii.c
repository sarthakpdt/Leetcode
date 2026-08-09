int stoneGameII(int* piles, int pilesSize) {
    int sum[pilesSize+1];
    sum[pilesSize]=0;
    for(int i=pilesSize-1;i>=0;i--){
        sum[i]=sum[i+1]+piles[i];
    }
    int dp[pilesSize+1][pilesSize+1];
    for(int i=0;i<=pilesSize;i++){
        for(int j=0;j<=pilesSize;j++){
            dp[i][j]=0;
        }
    }
    for(int i=pilesSize-1;i>=0;i--){
        for(int m=1;m<=pilesSize;m++){
            if(i+2*m>=pilesSize){
                dp[i][m]=sum[i];
            }
            else{
                for(int x=1;x<=2*m && i+x<=pilesSize;x++){
                    int a=sum[i]-sum[i+x];
                    int b=dp[i+x][m>x?m:x];
                    int curr=a+(sum[i+x]-b);
                    if(curr>dp[i][m]){
                        dp[i][m]=curr;
                    }
                }
            }
        }
    }
    return dp[0][1];
}