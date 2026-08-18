class Solution(object):
    def uniqueOccurrences(self, arr):
        freq={}
        for x in arr:
            if x in freq:
                freq[x]+=1
            else:
                freq[x]=1
        occurrences=set(freq.values())
        return len(freq)==len(occurrences)