class Solution(object):
    def maxValue(self, n, index, maxSum):
        def get_sum(v, l):
            if v>l:
                return (v+v-l+1)*l//2
            return (v+1)*v//2+(l-v)
        l=1
        r=maxSum
        ans=1
        while l<=r:
            m=(l+r)//2
            tot=m+get_sum(m-1, index)+get_sum(m-1, n-1-index)
            if tot<=maxSum:
                ans=m
                l=m+1
            else:
                r=m-1
        return ans