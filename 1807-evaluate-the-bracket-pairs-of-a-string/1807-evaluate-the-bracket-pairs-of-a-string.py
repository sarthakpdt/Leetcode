class Solution(object):
    def evaluate(self,s,knowledge):
        d={}
        for i in range(len(knowledge)):
            d[knowledge[i][0]]=knowledge[i][1]
        ans=""
        i=0
        while i<len(s):
            if s[i]=='(':
                j=i+1
                while s[j]!=')':
                    j+=1
                key=s[i+1:j]
                if key in d:
                    ans+=d[key]
                else:
                    ans+='?'
                i=j+1
            else:
                ans+=s[i]
                i+=1
        return ans