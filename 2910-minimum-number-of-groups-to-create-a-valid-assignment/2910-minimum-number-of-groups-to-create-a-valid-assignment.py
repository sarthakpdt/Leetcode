from collections import Counter
class Solution(object):
    def minGroupsForValidAssignment(self, balls):
        counts=Counter(balls).values()
        min_c=min(counts)
        for k in range(min_c,0,-1):
            valid=True
            total_boxes=0
            for c in counts:
                q=c//k
                r=c%k
                if r>q:
                    valid=False
                    break
                total_boxes+=(c+k)//(k+1)
            if valid:
                return total_boxes
        return len(balls)