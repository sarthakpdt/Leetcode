import collections
class Solution(object):
    def numMatchingSubseq(self, s, words):
        h=collections.defaultdict(list)
        for w in words:
            h[w[0]].append(iter(w[1:]))
        ans=0
        for c in s:
            q=h[c]
            h[c]=[]
            for it in q:
                nxt=next(it, None)
                if nxt is None:
                    ans+=1
                else:
                    h[nxt].append(it)
        return ans