class Solution(object):
    def fact(self,n):
        if (n==0):
            return 1
        elif (n<0):
            return -1
        else:
            return n*self.fact(n-1)
    def numberOfSets(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        a=n+k-1
        b=2*k
        c=a-b
        ans1=self.fact(a)
        ans2=self.fact(c)
        ans3=self.fact(b)
        ans=(ans1//(ans2*ans3))
        return ans%(10**9+7)