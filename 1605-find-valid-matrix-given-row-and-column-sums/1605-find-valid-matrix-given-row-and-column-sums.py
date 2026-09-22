class Solution(object):
    def restoreMatrix(self,rowSum,colSum):
        n=len(rowSum)
        m=len(colSum)
        ans=[[0]*m for i in range(n)]

        for i in range(n):
            for j in range(m):
                x=min(rowSum[i],colSum[j])
                ans[i][j]=x
                rowSum[i]-=x
                colSum[j]-=x

        return ans