class Solution(object):
    def minimumChanges(self, s, k):
        n=len(s)
        cost=[[0]*n for _ in range(n)]
        for l in range(n):
            for r in range(l+1,n):
                length=r-l+1
                ans=float('inf')
                for d in range(1,length):
                    if length%d==0:
                        changes=0
                        for i in range(d):
                            left=l+i
                            right=r-(d-1-i)
                            while left<right:
                                if s[left]!=s[right]:
                                    changes+=1
                                left+=d
                                right-=d
                        ans=min(ans,changes)
                cost[l][r]=ans
        dp=[[float('inf')]*(k+1) for _ in range(n+1)]
        dp[0][0]=0
        for i in range(2,n+1):
            for j in range(1,k+1):
                for p in range(2*j-2,i-1):
                    dp[i][j]=min(dp[i][j],dp[p][j-1]+cost[p][i-1])
        return dp[n][k]