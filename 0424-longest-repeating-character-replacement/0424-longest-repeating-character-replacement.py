class Solution(object):
    def characterReplacement(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        freq={}
        left=0
        maxx=0
        ans=0
        for right in range(len(s)):
            freq[s[right]]=freq.get(s[right],0)+1
            maxx=max(maxx,freq[s[right]])
            while (right-left+1)-maxx>k:
                freq[s[left]]-=1
                left+=1
            ans=max(ans,right-left+1)
        return ans