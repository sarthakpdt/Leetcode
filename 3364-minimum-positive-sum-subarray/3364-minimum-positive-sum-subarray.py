class Solution(object):
    def minimumSumSubarray(self, nums, l, r):
        """
        :type nums: List[int]
        :type l: int
        :type r: int
        :rtype: int
        """
        n=len(nums)
        res=[]
        for i in range(n):
            for j in range(l,r+1):
                a=i+j
                if (a<=n):
                    res.append(nums[i:a])
        summ=[]
        for i in res:
            total=sum(i)
            if total>0:
                summ.append(total)
        return min(summ) if summ else -1