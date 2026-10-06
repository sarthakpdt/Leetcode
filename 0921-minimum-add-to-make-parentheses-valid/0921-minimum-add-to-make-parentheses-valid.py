class Solution(object):
    def minAddToMakeValid(self, s):
        """
        :type s: str
        :rtype: int
        """
        count=0
        ans=0
        for i in s:
            if (i=='('):
                count+=1
            else:
                count-=1
                if count<0:
                    ans+=1
                    count=0
        ans+=count
        return ans