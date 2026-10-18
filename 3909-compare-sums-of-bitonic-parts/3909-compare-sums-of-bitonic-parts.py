class Solution(object):
    def compareBitonicSums(self, nums):
        n=len(nums)
        peak=0
        for i in range(1,n):
            if (nums[i]>nums[i-1]):
                peak=i
            else:
                break
        a=sum(nums[:peak+1])
        b=sum(nums[peak:])
        if (a>b):
            return 0
        elif (b>a):
            return 1
        else:
            return -1