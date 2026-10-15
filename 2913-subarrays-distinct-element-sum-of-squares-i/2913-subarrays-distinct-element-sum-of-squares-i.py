class Solution(object):
    def sumCounts(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n=len(nums)
        total=0
        for i in range(n):
            for j in range(i+1,n+1):
                sub=nums[i:j]
                dis=len(set(sub))
                total+=dis**2
        return total
