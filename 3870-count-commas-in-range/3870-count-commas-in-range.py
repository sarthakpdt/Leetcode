class Solution(object):
    def countCommas(self, n):
        """
        :type n: int
        :rtype: int
        """
        total=0
        if (n<1000):
            return 0
        for i in range(1000,n+1):
            num=i
            count=0
            while(num>0):
                num=num//10
                count+=1
            total+=(count-1)//3
        return total
