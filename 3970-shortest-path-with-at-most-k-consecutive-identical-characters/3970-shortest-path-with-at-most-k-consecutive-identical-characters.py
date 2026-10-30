import heapq
class Solution(object):
    def shortestPath(self,n,edges,labels,k):
        """
        :type n: int
        :type edges: List[List[int]]
        :type labels: str
        :type k: int
        :rtype: int
        """
        adj=[[] for i in range(n)]
        for u,v,w in edges:
            adj[u].append((v,w))
        dist={(0,1):0}
        heap=[(0,0,1)]
        while heap:
            cost,u,count=heapq.heappop(heap)
            if cost!=dist.get((u,count),float('inf')):
                continue
            if u==n-1:
                return cost
            for v,w in adj[u]:
                if labels[v]==labels[u]:
                    newcount=count+1
                else:
                    newcount=1
                if newcount>k:
                    continue
                newcost=cost+w
                state=(v,newcount)
                if newcost<dist.get(state,float('inf')):
                    dist[state]=newcost
                    heapq.heappush(heap,(newcost,v,newcount))
        return -1