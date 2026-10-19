class Solution(object):
    def numSubmat(self, mat):
        m,n=len(mat),len(mat[0])
        h=[0]*n
        ans=0
        for i in range(m):
            for j in range(n):
                h[j]=h[j]+1 if mat[i][j] else 0
            st=[]
            dp=[0]*n
            for j in range(n):
                while st and h[st[-1]]>=h[j]:
                    st.pop()
                if st:
                    k=st[-1]
                    dp[j]=dp[k]+h[j]*(j-k)
                else:
                    dp[j]=h[j]*(j+1)
                st.append(j)
                ans+=dp[j]
        return ans