from collections import deque
class Solution(object):
    def shortestPathBinaryMatrix(self, grid):
        n=len(grid)
        if (grid[0][0]==1 or grid[n-1][n-1]==1):
            return -1
        q=deque([(0,0,1)])
        grid[0][0]=1
        directions=[(-1,-1),(-1,0),(-1,1),(0,-1),(0,1),(1,-1),(1,0),(1,1)]
        while q:
            x,y,d=q.popleft()
            if (x==n-1 and y==n-1):
                return d
            for dx,dy in directions:
                a=x+dx
                b=y+dy
                if (a>=0 and a<n and b>=0 and b<n and grid[a][b]==0):
                    grid[a][b]=1
                    q.append((a,b,d+1))
        return -1