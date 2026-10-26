class Solution(object):
    def closedIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m=len(grid)
        n=len(grid[0])
        def dfs(i,j):
            if (i<0 or i>=m or j<0 or j>=n):
                return False
            if (grid[i][j]==1):
                return True
            grid[i][j]=1
            a=dfs(i+1,j)
            b=dfs(i-1,j)
            c=dfs(i,j+1)
            d=dfs(i,j-1)
            return a and b and c and d
        ans=0
        for i in range(1,m-1):
            for j in range(1,n-1):
                if (grid[i][j]==0):
                    if (dfs(i,j)):
                        ans+=1
        return ans