int max(int a,int b){
    return a>b?a:b;
}
int maximumAmount(int**coins,int m,int*ncol){
    int n=ncol[0];
    int***dp=(int***)malloc(m*sizeof(int**));
    for(int i=0;i<m;i++){
        dp[i]=(int**)malloc(n*sizeof(int*));
        for(int j=0;j<n;j++){
            dp[i][j]=(int*)malloc(3*sizeof(int));
            for(int k=0;k<3;k++){
                dp[i][j][k]=INT_MIN;
            }
        }
    }
    dp[0][0][0]=coins[0][0];
    if(coins[0][0]<0){
        dp[0][0][1]=0;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<3;k++){
                if(dp[i][j][k]==INT_MIN) continue;
                if(j+1<n){
                    int val=coins[i][j+1];
                    dp[i][j+1][k]=max(dp[i][j+1][k],dp[i][j][k]+val);
                    if(val<0&&k<2){
                        dp[i][j+1][k+1]=max(dp[i][j+1][k+1],dp[i][j][k]);
                    }
                }
                if(i+1<m){
                    int val=coins[i+1][j];
                    dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]+val);
                    if(val<0&&k<2){
                        dp[i+1][j][k+1]=max(dp[i+1][j][k+1],dp[i][j][k]);
                    }
                }
            }
        }
    }
    int ans=INT_MIN;
    for(int k=0;k<3;k++){
        ans=max(ans,dp[m-1][n-1][k]);
    }
    return ans;
}