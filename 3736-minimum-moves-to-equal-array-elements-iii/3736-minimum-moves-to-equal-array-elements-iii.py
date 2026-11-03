class Solution(object):
    def minMoves(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        maxi=max(nums)
        count=0
        for i in range(len(nums)):  
            count+=maxi-nums[i]
        return count