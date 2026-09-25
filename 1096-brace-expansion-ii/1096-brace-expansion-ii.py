class Solution(object):
    def braceExpansionII(self,expression):
        def solve(i):
            ans=set()
            cur={""}
            while i<len(expression) and expression[i]!='}':
                if expression[i]==',':
                    ans=ans|cur
                    cur={""}
                    i+=1
                elif expression[i]=='{':
                    a,i=solve(i+1)
                    b=set()
                    for x in cur:
                        for y in a:
                            b.add(x+y)
                    cur=b
                else:
                    b=set()
                    for x in cur:
                        b.add(x+expression[i])
                    cur=b
                    i+=1
            ans=ans|cur
            return ans,i+1
        ans,i=solve(0)
        return sorted(ans)