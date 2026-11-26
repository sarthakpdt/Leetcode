class Solution(object):
    def canAliceWin(self, n):
        """
        :type n: int
        :rtype: bool
        """
        a=10
        k=0
        while n>=a:
            n-=a
            a-=1
            k+=1
        return k%2==1
        