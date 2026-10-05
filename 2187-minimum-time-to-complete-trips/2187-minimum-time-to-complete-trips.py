class Solution(object):
    def minimumTime(self, time, totalTrips):
        low=1
        high=min(time)*totalTrips
        ans=high
        while low<=high:
            mid=(low+high)//2
            trips=sum(mid//t for t in time)
            if trips>=totalTrips:
                ans=mid
                high=mid-1
            else:
                low=mid+1
        return ans