int cmp1(const void*a,const void*b){return *(int*)a-*(int*)b;}
int cmp2(const void*a,const void*b){return (*(int**)a)[0]-(*(int**)b)[0];}

long long min(long long a,long long b){return a<b?a:b;}

long long minimumTotalDistance(int*robot,int robotSize,int**factory,int factorySize,int*factoryColSize){
    qsort(robot,robotSize,sizeof(int),cmp1);
    qsort(factory,factorySize,sizeof(int*),cmp2);

    long long dp[105][105];
    for(int i=0;i<=robotSize;i++){
        for(int j=0;j<=factorySize;j++){
            dp[i][j]=LLONG_MAX/2;
        }
    }

    dp[0][0]=0;

    for(int j=1;j<=factorySize;j++){
        dp[0][j]=0;
        for(int i=1;i<=robotSize;i++){
            dp[i][j]=dp[i][j-1];
            long long cost=0;
            for(int k=1;k<=factory[j-1][1]&&k<=i;k++){
                cost+=llabs((long long)robot[i-k]-factory[j-1][0]);
                dp[i][j]=min(dp[i][j],dp[i-k][j-1]+cost);
            }
        }
    }

    return dp[robotSize][factorySize];
}