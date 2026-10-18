class Solution(object):
    def smallestDivisor(self, nums, threshold):
        l=1
        r=max(nums)
        ans=r
        while l<=r:
            m=(l+r)//2
            s=0
            for x in nums:
                s+=(x+m-1)//m
            if s<=threshold:
                ans=m
                r=m-1
            else:
                l=m+1
        return ans