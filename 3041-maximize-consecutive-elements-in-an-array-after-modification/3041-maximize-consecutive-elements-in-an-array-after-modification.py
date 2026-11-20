class Solution(object):
    def maxSelectedElements(self,nums):
        nums.sort()
        dp={}
        maxi=0
        for i in nums:
            a=dp.get(i-1,0)+1
            b=dp.get(i,0)+1
            dp[i]=max(dp.get(i,0),a)
            dp[i+1]=max(dp.get(i+1,0),b)
            maxi=max(maxi,dp[i],dp[i+1])
        return maxi
