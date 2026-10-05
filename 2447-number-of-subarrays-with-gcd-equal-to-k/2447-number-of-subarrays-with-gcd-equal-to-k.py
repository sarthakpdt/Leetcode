from fractions import gcd
class Solution(object):
    def subarrayGCD(self, nums, k):
        ans=0
        for i in range(len(nums)):
            cur=0
            for j in range(i, len(nums)):
                cur=gcd(cur, nums[j])
                if cur==k:
                    ans+=1
                elif cur%k!=0:
                    break
        return ans