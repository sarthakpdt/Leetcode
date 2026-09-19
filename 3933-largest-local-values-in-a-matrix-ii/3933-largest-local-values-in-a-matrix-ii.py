class Solution(object):
    def countLocalMaximums(self,matrix):
        n=len(matrix)
        m=len(matrix[0])
        ans=0

        for x in range(1,201):
            p=[[0]*(m+1) for _ in range(n+1)]

            for i in range(n):
                for j in range(m):
                    if matrix[i][j]>x:
                        p[i+1][j+1]=1

            for i in range(n):
                for j in range(m):
                    p[i+1][j+1]+=p[i][j+1]+p[i+1][j]-p[i][j]

            for i in range(n):
                for j in range(m):
                    if matrix[i][j]!=x:
                        continue

                    r1=max(0,i-x)
                    r2=min(n-1,i+x)
                    c1=max(0,j-x)
                    c2=min(m-1,j+x)

                    z=p[r2+1][c2+1]-p[r1][c2+1]-p[r2+1][c1]+p[r1][c1]

                    if z==0:
                        ans+=1
                        continue

                    for r in [i-x,i+x]:
                        for c in [j-x,j+x]:
                            if 0<=r<n and 0<=c<m and matrix[r][c]>x:
                                z-=1

                    if z==0:
                        ans+=1

        return ans