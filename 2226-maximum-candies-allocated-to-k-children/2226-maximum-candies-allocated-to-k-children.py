class Solution(object):
    def maximumCandies(self,candies,k):
        low=1
        high=max(candies)
        ans=0

        while low<=high:
            mid=(low+high)//2
            count=0

            for x in candies:
                count+=x//mid

            if count>=k:
                ans=mid
                low=mid+1
            else:
                high=mid-1

        return ans