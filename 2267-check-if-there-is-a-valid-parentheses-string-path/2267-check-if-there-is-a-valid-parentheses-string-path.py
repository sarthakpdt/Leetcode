class Solution(object):
    def hasValidPath(self, grid):
        m=len(grid)
        n=len(grid[0])
        if (m+n-1)%2!=0:
            return False
        if grid[0][0]==')' or grid[m-1][n-1]=='(':
            return False
        dp=[[set() for j in range(n)] for i in range(m)]
        dp[0][0].add(1)
        for i in range(m):
            for j in range(n):
                if i==0 and j==0:
                    continue
                for balance in range(m+n):
                    if i>0 and balance in dp[i-1][j]:
                        if grid[i][j]=='(':
                            dp[i][j].add(balance+1)
                        elif balance>0:
                            dp[i][j].add(balance-1)
                    if j>0 and balance in dp[i][j-1]:
                        if grid[i][j]=='(':
                            dp[i][j].add(balance+1)
                        elif balance>0:
                            dp[i][j].add(balance-1)
        return 0 in dp[m-1][n-1]