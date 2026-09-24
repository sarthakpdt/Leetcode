class Solution(object):
    def smallestIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        count=0
        for i in nums:
            a=i
            total=0
            while a>0:
                digit=a%10
                total+=digit
                a=a//10
            if (total==count):
                return count
            count+=1
        return -1
        