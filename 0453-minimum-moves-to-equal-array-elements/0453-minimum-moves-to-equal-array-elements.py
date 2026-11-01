class Solution(object):
    def minMoves(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mini=min(nums)
        count=0
        for i in range(len(nums)):
            count+=nums[i]-mini
        return count 
                

        