class Solution(object):
    def minimumPairRemoval(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n=len(nums)
        count=0
        while True:
            sorted=True
            for i in range(n-1):
                if (nums[i]>nums[i+1]):
                    sorted=False
                    break
            if sorted:
                return count
            minn=float('inf')
            total=0
            for i in range(n-1):
                summ=nums[i]+nums[i+1]
                if (minn>summ):
                    minn=summ
                    total=i
            nums[total]=nums[total]+nums[total+1]
            nums.pop(total+1)
            n-=1
            count+=1