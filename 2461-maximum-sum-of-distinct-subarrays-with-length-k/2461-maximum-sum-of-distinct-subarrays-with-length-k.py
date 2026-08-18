class Solution(object):
    def maximumSubarraySum(self,nums,k):
        freq={}
        curr=0
        maxx=0
        left=0
        for right in range(len(nums)):
            curr+=nums[right]
            if nums[right] in freq:
                freq[nums[right]]+=1
            else:
                freq[nums[right]]=1
            while freq[nums[right]]>1:
                freq[nums[left]]-=1
                curr-=nums[left]
                left+=1
            if right-left+1==k:
                maxx=max(maxx,curr)
                freq[nums[left]]-=1
                curr-=nums[left]
                left+=1
        return maxx