from collections import deque

class Solution(object):
    def maximumSum(self,nums,m,l,r):
        n=len(nums)
        p=[0]*(n+1)

        for i in range(n):
            p[i+1]=p[i]+nums[i]

        dp=[0]*(n+1)
        ans=-10**30

        for k in range(1,m+1):
            ndp=[0]*(n+1)
            q=deque()

            for i in range(1,n+1):
                j=i-l

                if j>=0:
                    v=dp[j]-p[j]

                    while q and dp[q[-1]]-p[q[-1]]<=v:
                        q.pop()

                    q.append(j)

                while q and q[0]<i-r:
                    q.popleft()

                ndp[i]=ndp[i-1]

                if q:
                    v=p[i]+dp[q[0]]-p[q[0]]
                    ndp[i]=max(ndp[i],v)
                    ans=max(ans,v)

            dp=ndp

        return ans