class Solution(object):
    def longestSubarray(self,nums,limit):
        from collections import deque
        maxq=deque()
        minq=deque()
        left=0
        maxx=0
        for right in range(len(nums)):
            while maxq and nums[maxq[-1]]<nums[right]:
                maxq.pop()
            while minq and nums[minq[-1]]>nums[right]:
                minq.pop()
            maxq.append(right)
            minq.append(right)
            while nums[maxq[0]]-nums[minq[0]]>limit:
                if maxq[0]==left:
                    maxq.popleft()
                if minq[0]==left:
                    minq.popleft()
                left+=1
            if maxx<right-left+1:
                maxx=right-left+1
        return maxx