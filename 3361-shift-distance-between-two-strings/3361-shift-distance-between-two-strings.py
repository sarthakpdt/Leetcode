class Solution(object):
    def shiftDistance(self, s, t, nextCost, previousCost):
        p_next=[0]*53
        p_prev=[0]*53
        for i in range(52):
            p_next[i+1]=p_next[i]+nextCost[i%26]
            p_prev[i+1]=p_prev[i]+previousCost[i%26]
        ans=0
        for i in range(len(s)):
            u=ord(s[i])-97
            v=ord(t[i])-97
            f_cost=p_next[v if v>=u else v+26]-p_next[u]
            b_idx1=u if u>=v else u+26
            b_idx2=v+1
            b_cost=p_prev[b_idx1+1]-p_prev[b_idx2]
            ans+=min(f_cost,b_cost)
        return ans