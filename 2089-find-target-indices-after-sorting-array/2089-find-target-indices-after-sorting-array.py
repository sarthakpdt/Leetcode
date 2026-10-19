class Solution(object):
    def targetIndices(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        lst=[]
        nums.sort()
        n=len(nums)
        for i in range(n):
            if (nums[i]==target):
                lst.append(i)
        return lst