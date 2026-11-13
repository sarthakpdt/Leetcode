
class Solution(object):
    def robotWithString(self,s):
        stack=[]
        ans=""
        mini=['']*len(s)
        mini[-1]=s[-1]
        for i in range(len(s)-2,-1,-1):
            mini[i]=min(s[i],mini[i+1])
        for i in range(len(s)):
            stack.append(s[i])
            while stack and (i==len(s)-1 or stack[-1]<=mini[i+1]):
                ans+=stack.pop()
        return ans
