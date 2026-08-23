class Solution(object):
    def maxRemovals(self, source, pattern, targetIndices):
        """
        :type source: str
        :type pattern: str
        :type targetIndices: List[int]
        :rtype: int
        """
        n=len(source)
        m=len(pattern)
        removable=set(targetIndices)
        dp=[-1]*(m+1)
        dp[0]=0
        for i in range(n):
            new=dp[:]
            for j in range(m+1):
                if dp[j]==-1:
                    continue
                if i in removable:
                    new[j]=max(new[j],dp[j]+1)
                if j<m and source[i]==pattern[j]:
                    new[j+1]=max(new[j+1],dp[j])
            dp=new
        return dp[m]