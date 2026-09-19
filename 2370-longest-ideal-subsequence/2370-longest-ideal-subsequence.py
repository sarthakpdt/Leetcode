class Solution(object):
    def longestIdealString(self,s,k):
        dp=[0]*26

        for ch in s:
            x=ord(ch)-ord('a')
            best=0

            for j in range(max(0,x-k),min(25,x+k)+1):
                best=max(best,dp[j])

            dp[x]=best+1

        return max(dp)