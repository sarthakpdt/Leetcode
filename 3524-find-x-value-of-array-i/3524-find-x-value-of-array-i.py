class Solution(object):
    def resultArray(self,nums,k):
        dp=[0]*k
        ans=[0]*k
        for num in nums:
            new=[0]*k
            new[num%k]+=1
            for r in range(k):
                if dp[r]>0:
                    new[(r*(num%k))%k]+=dp[r]
            dp=new
            for r in range(k):
                ans[r]+=dp[r]
        return ans