class Solution(object):
    def numOfSubarrays(self,arr):
        odd=0
        even=1
        total=0
        ans=0
        mod=10**9+7
        for i in arr:
            total+=i
            if (total%2==0):
                ans+=odd
                even+=1
            else:
                ans+=even
                odd+=1
        return ans%mod