class Solution(object):
    def maximumWeight(self,intervals):
        n=len(intervals)
        a=[]
        for i in range(n):
            a.append((intervals[i][0],intervals[i][1],intervals[i][2],i))
        a.sort()
        st=[x[0] for x in a]
        import bisect
        dp=[[(0,[]) for _ in range(5)] for _ in range(n+1)]
        for i in range(n-1,-1,-1):
            l,r,w,idx=a[i]
            j=bisect.bisect_right(st,r)
            for k in range(1,5):
                skip=dp[i+1][k]
                score=w+dp[j][k-1][0]
                ans=sorted([idx]+dp[j][k-1][1])
                if score>skip[0]:
                    dp[i][k]=(score,ans)
                elif score<skip[0]:
                    dp[i][k]=skip
                else:
                    if ans<skip[1]:
                        dp[i][k]=(score,ans)
                    else:
                        dp[i][k]=skip
        return dp[0][4][1]