from collections import Counter
class Solution(object):
    def unequalTriplets(self, nums):
        cnt=Counter(nums)
        ans=0
        left=0
        right=len(nums)
        for freq in cnt.values():
            right-=freq
            ans+=left*freq*right
            left+=freq
        return ans