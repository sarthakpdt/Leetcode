class Solution(object):
    def minimumDeletions(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        minn=nums[0]
        maxx=nums[0]
        n=len(nums)
        j=0
        k=0
        for i in range(1,n):
            if (minn>nums[i]):
                minn=nums[i]
                j=i
            if (maxx<nums[i]):
                maxx=nums[i]
                k=i
        a=max(j,k)+1
        b=n-min(j,k)
        c=min(j,k)+1+n-max(j,k)
        return min(a,b,c)