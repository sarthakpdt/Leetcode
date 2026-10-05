import bisect
class Solution(object):
    def lengthOfLIS(self, nums):
        tails=[]
        for v in nums:
            i=bisect.bisect_left(tails, v)
            if i==len(tails):
                tails.append(v)
            else:
                tails[i]=v
        return len(tails)