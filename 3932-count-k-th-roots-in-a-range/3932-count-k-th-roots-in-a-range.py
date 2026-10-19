import math
class Solution(object):
    def countKthRoots(self, l, r, k):
        if k==1:
            return r-l+1
        def count_up_to(n):
            if n<0:
                return 0
            if n==0:
                return 1
            ans=int(math.pow(n, 1.0/k))
            while (ans+1)**k<=n:
                ans+=1
            while ans**k>n:
                ans-=1
            return ans+1
        return count_up_to(r)-count_up_to(l-1)