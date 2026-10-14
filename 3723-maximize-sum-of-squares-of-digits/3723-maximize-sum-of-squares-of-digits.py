class Solution(object):
    def maxSumOfSquares(self, num, sum):
        """
        :type num: int
        :type sum: int
        :rtype: str
        """
        if (sum>num*9):
            return ""
        ans=""
        for i in range(num):
            if (sum>=9):
                ans+="9"
                sum-=9
            else:
                ans+=str(sum)
                sum=0
        return ans