class Solution(object):
    def smallestUniqueSubarray(self,nums):
        n=len(nums)
        sa=list(range(n))
        rank=nums[:]
        k=1
        while (k<n):
            sa.sort(key=lambda i:(rank[i],rank[i+k] if i+k<n else -1))
            temp=[0]*n
            for i in range(1,n):
                a=sa[i-1]
                b=sa[i]
                x=(rank[a],rank[a+k] if a+k<n else -1)
                y=(rank[b],rank[b+k] if b+k<n else -1)
                temp[b]=temp[a]+(x!=y)
            rank=temp
            if (rank[sa[-1]]==n-1):
                break
            k*=2
        pos=[0]*n
        for i in range(n):
            pos[sa[i]]=i
        lcp=[0]*n
        h=0
        for i in range(n):
            r=pos[i]
            if (r==n-1):
                h=0
                continue
            j=sa[r+1]
            while (i+h<n and j+h<n and nums[i+h]==nums[j+h]):
                h+=1
            lcp[r]=h
            if (h>0):
                h-=1
        ans=n
        for i in range(n):
            r=pos[i]
            left=0
            right=0
            if (r>0):
                left=lcp[r-1]
            if (r<n-1):
                right=lcp[r]
            maxi=max(left,right)
            if (maxi<n-i):
                ans=min(ans,maxi+1)
        return ans