class Solution(object):
    def minWindow(self,s,t):
        f={}
        for c in t:
            f[c]=f.get(c,0)+1
        l=0
        count=len(t)
        ans=""
        for r in range(len(s)):
            if s[r] in f:
                if f[s[r]]>0:
                    count-=1
                f[s[r]]-=1
            while count==0:
                if not ans or r-l+1<len(ans):
                    ans=s[l:r+1]
                if s[l] in f:
                    f[s[l]]+=1
                    if f[s[l]]>0:
                        count+=1
                l+=1
        return ans