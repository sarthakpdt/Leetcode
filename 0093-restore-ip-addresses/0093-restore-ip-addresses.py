class Solution(object):
    def restoreIpAddresses(self,s):
        ans=[]
        def solve(i,a):
            if len(a)==4:
                if i==len(s):
                    ans.append(".".join(a))
                return
            for j in range(i,min(i+3,len(s))):
                x=s[i:j+1]
                if len(x)>1 and x[0]=='0':
                    break
                if int(x)>255:
                    break
                solve(j+1,a+[x])
        solve(0,[])
        return ans