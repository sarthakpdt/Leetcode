class Solution(object):
    def maxRepOpt1(self, text):
        """
        :type text: str
        :rtype: int
        """
        freq={}
        for ch in text:
            freq[ch]=freq.get(ch,0)+1
        maxx=float('-inf')
        for ch in freq:
            left=0
            count=0
            for right in range(len(text)):
                if text[right]==ch:
                    count+=1
                while right-left+1-count>1:
                    if (text[left]==ch):
                        count-=1
                    left+=1
                maxx=max(maxx,min(right-left+1,freq[ch]))
        return maxx
