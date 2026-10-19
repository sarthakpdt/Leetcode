class Solution(object):
    def kConcatenationMaxSum(self, arr, k):
        MOD=10**9+7
        def kadane(a):
            m=0
            cur=0
            for x in a:
                cur=max(0, cur+x)
                m=max(m, cur)
            return m
        s=sum(arr)
        if k==1:
            return kadane(arr)%MOD
        if s>0:
            return (kadane(arr*2)+(k-2)*s)%MOD
        return kadane(arr*2)%MOD