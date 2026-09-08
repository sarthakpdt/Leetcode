class Solution(object):
    def minGroups(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: int
        """
        intervals.sort()
        pq=[]
        for left,right in intervals:
            if pq and pq[0]<left:
                heapq.heappop(pq)
            heapq.heappush(pq,right)
        return len(pq)