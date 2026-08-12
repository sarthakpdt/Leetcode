class Solution(object):
    def minWindow(self,s,t):
        if len(t)>len(s):
            return ""
        freq={}
        for ch in t:
            freq[ch]=freq.get(ch,0)+1
        left=0
        count=len(t)
        start=0
        minlen=float('inf')
        for right in range(len(s)):
            if s[right] in freq:
                if freq[s[right]]>0:
                    count-=1
                freq[s[right]]-=1
            while count==0:
                if right-left+1<minlen:
                    minlen=right-left+1
                    start=left
                if s[left] in freq:
                    freq[s[left]]+=1
                    if freq[s[left]]>0:
                        count+=1
                left+=1
        if minlen==float('inf'):
            return ""
        return s[start:start+minlen]