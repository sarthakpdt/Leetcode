class Solution(object):
    def maxSum(self, nums, k):
        mod=10**9+7
        count=[0]*32
        for x in nums:
            for i in range(32):
                if (x&(1<<i)):
                    count[i]+=1
        ans=0
        for i in range(k):
            num=0
            for j in range(32):
                if (count[j]>0):
                    num|=(1<<j)
                    count[j]-=1
            ans=(ans+num*num)%mod
        return ans