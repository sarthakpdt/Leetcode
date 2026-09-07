class Solution(object):
    def maxDepth(self, s):
        """
        :type s: str
        :rtype: int
        """
        maxx=0
        curr=0
        for i in s:
            if i=="(":
                curr+=1
                if curr>maxx:
                    maxx=curr
            elif i==")":
                curr-=1
        return maxx