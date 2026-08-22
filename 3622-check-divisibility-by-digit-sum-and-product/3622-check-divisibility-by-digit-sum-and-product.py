class Solution(object):
    def checkDivisibility(self, n):
        """
        :type n: int
        :rtype: bool
        """
        nums=n
        final=n
        b=0
        while (n>0):
            a=n%10
            b+=a
            n=n//10
        bp=1
        while (nums>0):
            ap=nums%10
            bp*=ap
            nums=nums//10
        res=bp+b
        if (final%res==0):
            return True
        else:
            return False
        