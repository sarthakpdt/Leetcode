class Solution(object):
    def numFactoredBinaryTrees(self, arr):
        mod=10**9+7
        arr.sort()
        n=len(arr)
        dp=[1]*n
        pos={}
        for i in range(n):
            pos[arr[i]]=i
        for i in range(n):
            for j in range(i):
                if (arr[i]%arr[j]==0):
                    b=arr[i]//arr[j]
                    if (b in pos and pos[b]<i):
                        dp[i]=(dp[i]+dp[j]*dp[pos[b]])%mod
        return sum(dp)%mod