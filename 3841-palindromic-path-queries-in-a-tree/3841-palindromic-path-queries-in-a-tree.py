class Solution(object):
    def palindromePath(self,n,edges,s,queries):
        """
        :type n: int
        :type edges: List[List[int]]
        :type s: str
        :type queries: List[str]
        :rtype: List[bool]
        """
        adj=[[] for i in range(n)]
        for u,v in edges:
            adj[u].append(v)
            adj[v].append(u)
        parent=[-1]*n
        depth=[0]*n
        tin=[0]*n
        tout=[0]*n
        timer=0
        stack=[(0,-1,0)]
        while stack:
            u,p,state=stack.pop()
            if state==0:
                parent[u]=p
                tin[u]=timer
                timer+=1
                stack.append((u,p,1))
                for v in reversed(adj[u]):
                    if v!=p:
                        depth[v]=depth[u]+1
                        stack.append((v,u,0))
            else:
                tout[u]=timer-1
        LOG=max(1,n.bit_length())
        up=[parent[:]]
        for j in range(1,LOG):
            prev=up[-1]
            curr=[-1]*n
            for i in range(n):
                if prev[i]!=-1:
                    curr[i]=prev[prev[i]]
            up.append(curr)
        def lca(u,v):
            if depth[u]<depth[v]:
                u,v=v,u
            diff=depth[u]-depth[v]
            bit=0
            while diff:
                if diff&1:
                    u=up[bit][u]
                diff>>=1
                bit+=1
            if u==v:
                return u
            for j in range(LOG-1,-1,-1):
                if up[j][u]!=up[j][v]:
                    u=up[j][u]
                    v=up[j][v]
            return parent[u]
        bit=[0]*(n+2)
        def add(i,val):
            i+=1
            while i<=n:
                bit[i]^=val
                i+=i&-i
        def point(i):
            i+=1
            ans=0
            while i>0:
                ans^=bit[i]
                i-=i&-i
            return ans
        def range_xor(left,right,val):
            add(left,val)
            if right+1<n:
                add(right+1,val)
        masks=[1<<(ord(c)-ord('a')) for c in s]
        for u in range(n):
            range_xor(tin[u],tout[u],masks[u])
        ans=[]
        for query in queries:
            parts=query.split()
            if parts[0]=="update":
                u=int(parts[1])
                newmask=1<<(ord(parts[2])-ord('a'))
                delta=masks[u]^newmask
                if delta:
                    range_xor(tin[u],tout[u],delta)
                    masks[u]=newmask
            else:
                u=int(parts[1])
                v=int(parts[2])
                w=lca(u,v)
                mask=point(tin[u])^point(tin[v])^masks[w]
                ans.append((mask&(mask-1))==0)
        return ans
