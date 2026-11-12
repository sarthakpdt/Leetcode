class Solution(object):
    def maxWidthRamp(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        stack=[]
        for i in range(len(nums)):
            if (not stack or nums[i]<nums[stack[-1]]):
                stack.append(i)
        maxi=0
        for j in range(len(nums)-1,-1,-1):
            while stack and nums[stack[-1]]<=nums[j]:
                i=stack.pop()
                maxi=max(maxi,j-i)
        return maxi