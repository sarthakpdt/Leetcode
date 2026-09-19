class Solution(object):
    def shortestSuperstring(self,words):
        n=len(words)
        o=[[0]*n for _ in range(n)]

        for i in range(n):
            for j in range(n):
                for k in range(min(len(words[i]),len(words[j])),0,-1):
                    if words[i][-k:]==words[j][:k]:
                        o[i][j]=k
                        break

        dp=[[""]*n for _ in range(1<<n)]

        for i in range(n):
            dp[1<<i][i]=words[i]

        for mask in range(1<<n):
            for last in range(n):
                if dp[mask][last]=="":
                    continue

                for i in range(n):
                    if mask&(1<<i):
                        continue

                    nm=mask|(1<<i)
                    s=dp[mask][last]+words[i][o[last][i]:]

                    if dp[nm][i]=="" or len(s)<len(dp[nm][i]):
                        dp[nm][i]=s

        ans=""

        for i in range(n):
            s=dp[(1<<n)-1][i]

            if ans=="" or len(s)<len(ans):
                ans=s

        return ans