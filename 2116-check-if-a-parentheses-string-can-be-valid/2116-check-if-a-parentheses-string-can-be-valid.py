class Solution(object):
    def canBeValid(self, s, locked):
        """
        :type s: str
        :type locked: str
        :rtype: bool
        """
        n=len(s)
        if n%2==1:
            return False
        x=0
        for i in range(n):
            if locked[i]=='0' or s[i]=='(':
                x+=1
            else:
                x-=1
            if x<0:
                return False
        x=0
        for i in range(n-1,-1,-1):
            if locked[i]=='0' or s[i]==')':
                x+=1
            else:
                x-=1
            if x<0:
                return False
        return True
        
