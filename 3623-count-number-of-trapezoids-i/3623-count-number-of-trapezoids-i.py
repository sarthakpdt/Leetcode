from collections import defaultdict
class Solution(object):
    def countTrapezoids(self, points):
        mod=10**9+7
        yc=defaultdict(int)
        for x,y in points:
            yc[y]+=1
        pc=[]
        for c in yc.values():
            if c>=2:
                pc.append(c*(c-1)//2)
        ans=0
        tp=0
        for p in pc:
            ans=(ans+p*tp)%mod
            tp=(tp+p)%mod
        return ans