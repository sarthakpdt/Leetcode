class Solution(object):
    def makeSmallestPalindrome(self, s):
        s_list=list(s)
        n=len(s_list)
        for i in range(n//2):
            m=min(s_list[i],s_list[n-1-i])
            s_list[i]=m
            s_list[n-1-i]=m
        return "".join(s_list)