class Solution(object):
    def maximumLengthSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        fre={}
        i=0
        left=0
        ans=0
        for i in range(len(s)):
            fre[s[i]]=fre.get(s[i],0)+1
            while (fre[s[i]]>2):
                fre[s[left]]-=1
                left+=1
            ans=max(ans,i-left+1)
        return ans
            
