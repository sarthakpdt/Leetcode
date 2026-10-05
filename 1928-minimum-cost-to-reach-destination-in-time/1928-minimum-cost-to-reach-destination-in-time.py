class Solution(object):

    def minCost(self, maxTime, edges, passingFees):
        n=len(passingFees)
        dp=[[float("inf")]*n for _ in range(maxTime+1)]
        dp[0][0]=passingFees[0]
        for t in range(1,maxTime+1):
            for u,v,time in edges:
                if t>=time:
                    if dp[t-time][u]!=float("inf"):
                        dp[t][v]=min(dp[t][v],dp[t-time][u]+passingFees[v])
                    if dp[t-time][v]!=float("inf"):
                        dp[t][u]=min(dp[t][u],dp[t-time][v]+passingFees[u])
        res=min(dp[t][n-1] for t in range(maxTime+1))
        return res if res!=float("inf") else -1