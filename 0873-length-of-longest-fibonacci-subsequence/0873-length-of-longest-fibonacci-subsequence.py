class Solution(object):
    def lenLongestFibSubseq(self, arr):
        n=len(arr)
        pos={x:i for i,x in enumerate(arr)}
        dp={}
        ans=0
        for k in range(n):
            for j in range(k):
                diff=arr[k]-arr[j]
                if diff in pos and pos[diff]<j:
                    i=pos[diff]
                    dp[j,k]=dp.get((i,j),2)+1
                    ans=max(ans,dp[j,k])
        return ans if ans>=3 else 0