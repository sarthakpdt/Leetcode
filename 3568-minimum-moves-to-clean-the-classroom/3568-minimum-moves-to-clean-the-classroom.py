class Solution(object):
    def minMoves(self, classroom, energy):
        """
        :type classroom: List[str]
        :type energy: int
        :rtype: int
        """
        from collections import deque
        m=len(classroom)
        n=len(classroom[0])
        litter={}
        cnt=0
        sr=0
        sc=0
        for i in range(m):
            for j in range(n):
                if classroom[i][j]=='S':
                    sr=i
                    sc=j
                if classroom[i][j]=='L':
                    litter[(i,j)]=cnt
                    cnt+=1
        if cnt==0:
            return 0
        q=deque()
        q.append((sr,sc,energy,0,0))
        visited={}
        while q:
            r,c,e,mask,moves=q.popleft()
            if mask==(1<<cnt)-1:
                return moves
            state=(r,c,mask)
            if state in visited and visited[state]>=e:
                continue
            visited[state]=e
            for dr,dc in [(1,0),(-1,0),(0,1),(0,-1)]:
                nr=r+dr
                nc=c+dc
                if nr<0 or nr>=m or nc<0 or nc>=n:
                    continue
                if classroom[nr][nc]=='X':
                    continue
                if e==0:
                    continue
                ne=e-1
                nmask=mask
                if classroom[nr][nc]=='L':
                    nmask=nmask|(1<<litter[(nr,nc)])
                if classroom[nr][nc]=='R':
                    ne=energy
                q.append((nr,nc,ne,nmask,moves+1))
        return -1