class Solution(object):
    def mostCompetitive(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        stack=[]
        n=len(nums)
        for i,nums in enumerate(nums):
            while stack and stack[-1]>nums and len(stack)+(n-i)>k:
                stack.pop()
            if len(stack)<k:
                stack.append(nums)
        return stack
        
