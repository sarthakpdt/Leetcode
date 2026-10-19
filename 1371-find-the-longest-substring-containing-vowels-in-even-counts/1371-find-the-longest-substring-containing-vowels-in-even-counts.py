class Solution(object):
    def findTheLongestSubstring(self, s):
        d={0:-1}
        mask=0
        ans=0
        vowels={"a": 1, "e": 2, "i": 4, "o": 8, "u": 16}
        for i, c in enumerate(s):
            if c in vowels:
                mask^=vowels[c]
            if mask in d:
                ans=max(ans, i-d[mask])
            else:
                d[mask]=i
        return ans