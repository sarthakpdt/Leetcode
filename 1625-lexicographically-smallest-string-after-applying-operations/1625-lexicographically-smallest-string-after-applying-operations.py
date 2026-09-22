class Solution(object):
    def findLexSmallestString(self, s, a, b):
        n=len(s)
        ans=s
        q=[s]
        seen={s}
        while q:
            curr=q.pop(0)
            if curr<ans:
                ans=curr
            lst=list(curr)
            for i in range(1,n,2):
                lst[i]=str((int(lst[i])+a)%10)
            added="".join(lst)
            if added not in seen:
                seen.add(added)
                q.append(added)
            rotated=curr[-b:]+curr[:-b]
            if rotated not in seen:
                seen.add(rotated)
                q.append(rotated)
        return ans