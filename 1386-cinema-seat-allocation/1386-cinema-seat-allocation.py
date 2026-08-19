class Solution(object):
    def maxNumberOfFamilies(self, n, reservedSeats):
        """
        :type n: int
        :type reservedSeats: List[List[int]]
        :rtype: int
        """
        rows={}
        for r,s in reservedSeats:
            if r not in rows:
                rows[r]=set()
            rows[r].add(s)
        ans=(n-len(rows))*2
        for r in rows:
            seats=rows[r]
            left=2 not in seats and 3 not in seats and 4 not in seats and 5 not in seats
            middle=4 not in seats and 5 not in seats and 6 not in seats and 7 not in seats
            right=6 not in seats and 7 not in seats and 8 not in seats and 9 not in seats
            if left and right:
                ans+=2
            elif left or middle or right:
                ans+=1
        return ans
