class Solution(object):
    def countCommas(self, n):
        """
        :type n: int
        :rtype: int
            """
        total=0
        digit=4
        while 10**(digit-1)<=n:
            start=10**(digit-1)
            end=min(n,10**digit-1)
            total+=(end-start+1)*((digit-1)//3)
            digit+=1
        return total
