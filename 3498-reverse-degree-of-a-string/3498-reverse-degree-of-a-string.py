class Solution(object):
    def reverseDegree(self, s):
        """
        :type s: str
        :rtype: int
        """
        total=0
        for i in range(len(s)):
            a=27-(ord(s[i])-96)
            j=i+1
            pr=a*j
            total+=pr
        return total
        