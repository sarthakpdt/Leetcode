class Solution(object):
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        g.sort()
        s.sort()
        child=0
        co=0
        while (child<len(g) and co<len(s)):
            if (s[co]>=g[child]):
                child+=1
            co+=1
        return child
        