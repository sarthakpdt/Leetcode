class Solution(object):
    def maximalNetworkRank(self, n, roads):
        deg=[0]*n
        adj=[set() for _ in range(n)]
        for u, v in roads:
            deg[u]+=1
            deg[v]+=1
            adj[u].add(v)
            adj[v].add(u)
        ans=0
        for i in range(n):
            for j in range(i+1, n):
                r=deg[i]+deg[j]-(1 if j in adj[i] else 0)
                if r>ans:
                    ans=r
        return ans