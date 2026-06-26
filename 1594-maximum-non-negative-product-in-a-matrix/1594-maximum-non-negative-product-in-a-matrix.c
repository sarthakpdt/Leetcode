#define MOD 1000000007
long long max(long long a, long long b){
    return (a<b)?b:a;
}
long long min(long long a, long long b){
    return (a>b)?b:a;
}
int maxProductPath(int** grid, int gridSize, int* gridColSize) {
    int m=gridSize;
    int n=gridColSize[0];
    long long maxdp[m][n];
    long long mindp[m][n];
    maxdp[0][0]=mindp[0][0]=grid[0][0];
    for (int i=1;i<m;i++){
        maxdp[i][0]=mindp[i][0]=maxdp[i-1][0]*grid[i][0];
    }
    for (int i=1;i<n;i++){
        maxdp[0][i]=mindp[0][i]=maxdp[0][i-1]*grid[0][i];
    }
    for (int i=1;i<m;i++){
        for (int j=1;j<n;j++){
            long long val=grid[i][j];
            if (val>=0){
                maxdp[i][j]=max(maxdp[i-1][j],maxdp[i][j-1])*val;
                mindp[i][j]=min(mindp[i-1][j],mindp[i][j-1])*val;
            }
            else{
                maxdp[i][j]=min(mindp[i-1][j],mindp[i][j-1])*val;
                mindp[i][j]=max(maxdp[i-1][j],maxdp[i][j-1])*val;
            }
        }
    }
    long long res=maxdp[m-1][n-1];
    return (res<0)?-1:(int)(res%MOD);
}