import collections
class Solution(object):
    def maxPointsInsideSquare(self, points, s):
        d=collections.defaultdict(list)
        for i in range(len(points)):
            r=max(abs(points[i][0]), abs(points[i][1]))
            d[s[i]].append(r)
        lim=float("inf")
        for tag in d:
            d[tag].sort()
            if len(d[tag])>1:
                lim=min(lim, d[tag][1])
        ans=0
        for tag in d:
            if d[tag][0]<lim:
                ans+=1
        return ans