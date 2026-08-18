class Solution(object):
    def maxOperations(self,nums,k):
        nums.sort()
        left=0
        right=len(nums)-1
        count=0
        while left<right:
            curr=nums[left]+nums[right]
            if curr==k:
                count+=1
                left+=1
                right-=1
            elif curr<k:
                left+=1
            else:
                right-=1
        return count