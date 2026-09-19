class Solution(object):
    def firstMissingPositive(self,nums):
        n=len(nums)

        for i in range(n):
            while nums[i]>0 and nums[i]<=n and nums[nums[i]-1]!=nums[i]:
                x=nums[i]
                nums[i],nums[x-1]=nums[x-1],nums[i]

        for i in range(n):
            if nums[i]!=i+1:
                return i+1

        return n+1