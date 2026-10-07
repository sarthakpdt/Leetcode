class Solution(object):
    def removeInvalidParentheses(self, s):
        ans=[]
        found=False
        q=[s]
        visited=set()
        visited.add(s)
        while q:
            curr=q.pop(0)
            if self.valid(curr):
                ans.append(curr)
                found=True
            if found:
                continue
            for i in range(len(curr)):
                if (curr[i]!='(' and curr[i]!=')'):
                    continue
                temp=curr[:i]+curr[i+1:]
                if temp not in visited:
                    visited.add(temp)
                    q.append(temp)
        return ans
    def valid(self,s):
        count=0
        for i in s:
            if (i=='('):
                count+=1
            elif (i==')'):
                count-=1
                if count<0:
                    return False
        return count==0