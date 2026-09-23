class Solution(object):
    def minOperations(self, nums, x):
        """
        :type nums: List[int]
        :type x: int
        :rtype: int
        """
        target=sum(nums)-x
        if target<0:
            return -1
        if target==0:
            return len(nums)
        l=0
        total=0
        maxx=-1
        for i in range(len(nums)):
            total+=nums[i]
            while total>target and l<=i:
                total-=nums[l]
                l+=1
            if total==target:
                maxx=max(maxx,i-l+1)
        if maxx==-1:
            return -1
        return len(nums)-maxx