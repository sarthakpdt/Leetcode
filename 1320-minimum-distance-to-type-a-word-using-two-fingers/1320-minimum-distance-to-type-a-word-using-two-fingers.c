int get_d(int a,int b){
    if(a==26)return 0;
    return abs(a/6-b/6)+abs(a%6-b%6);
}

int minimumDistance(char* word){
    int n=strlen(word);
    int dp[301][27]; 
    for(int i=0;i<=n;i++){
        for(int j=0;j<=26;j++)dp[i][j]=1000;
    }
    dp[0][26]=0; 
    for(int i=0;i<n;i++){
        int cur=word[i]-'A';
        int prev=(i==0)?26:word[i-1]-'A';
        for(int other=0;other<=26;other++){
            if(dp[i][other]==1000)continue;
            int cost1=dp[i][other]+get_d(prev,cur);
            if(cost1<dp[i+1][other])dp[i+1][other]=cost1;
            int cost2=dp[i][other]+get_d(other,cur);
            if(cost2<dp[i+1][prev])dp[i+1][prev]=cost2;
        }
    }
    int res=1000;
    for(int j=0;j<=26;j++){
        if(dp[n][j]<res)res=dp[n][j];
    }
    return res;
}