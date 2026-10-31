class Solution(object):
    def criticalConnections(self,n,connections):
        """
        :type n: int
        :type connections: List[List[int]]
        :rtype: List[List[int]]
        """
        adj=[[] for i in range(n)]
        for u,v in connections:
            adj[u].append(v)
            adj[v].append(u)
        disc=[-1]*n
        low=[0]*n
        ans=[]
        timer=[0]
        for start in range(n):
            if disc[start]!=-1:
                continue
            disc[start]=timer[0]
            low[start]=timer[0]
            timer[0]+=1
            stack=[(start,-1,0)]
            while stack:
                u,parent,index=stack[-1]
                if index<len(adj[u]):
                    v=adj[u][index]
                    stack[-1]=(u,parent,index+1)
                    if v==parent:
                        continue
                    if disc[v]==-1:
                        disc[v]=timer[0]
                        low[v]=timer[0]
                        timer[0]+=1
                        stack.append((v,u,0))
                    else:
                        low[u]=min(low[u],disc[v])
                else:
                    stack.pop()
                    if parent!=-1:
                        low[parent]=min(low[parent],low[u])
                        if low[u]>disc[parent]:
                            ans.append([parent,u])
        return ans