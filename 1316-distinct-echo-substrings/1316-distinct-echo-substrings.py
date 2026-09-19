class Solution(object):
    def distinctEchoSubstrings(self,text):
        n=len(text)
        dp=[[0]*(n+1) for _ in range(n+1)]
        ans=set()

        for i in range(n-1,-1,-1):
            for j in range(n-1,-1,-1):
                if text[i]==text[j]:
                    dp[i][j]=dp[i+1][j+1]+1

        for i in range(n):
            for l in range(1,n-i+1):
                j=i+l

                if j+l>n:
                    break

                if dp[i][j]>=l:
                    ans.add(text[i:j+l])

        return len(ans)