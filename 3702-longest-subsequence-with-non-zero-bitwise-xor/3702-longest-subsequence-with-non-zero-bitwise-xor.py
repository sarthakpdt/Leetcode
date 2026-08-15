class Solution(object):
    def longestSubsequence(self,nums):
        s=len(nums)
        x=nums[0]
        for i in range(1,s):
            x=x^nums[i]
        if x!=0:
            return s
        for i in range(s):
            if nums[i]!=0:
                return s-1
        return 0