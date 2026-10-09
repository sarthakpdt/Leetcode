class Solution(object):
    def minInsertions(self, s):
        ans=0
        r=0
        for i in range(len(s)):
            if s[i]=='(':
                if r%2!=0:
                    ans+=1
                    r-=1
                r+=2
            else:
                r-=1
                if r<0:
                    ans+=1
                    r+=2
        return ans+r