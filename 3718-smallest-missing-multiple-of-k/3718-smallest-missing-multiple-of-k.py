class Solution(object):
    def missingMultiple(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        res=[]
        for i in range(1,102):
            res.append(i*k)
        for i in res:
            if i not in nums:
                return i
        