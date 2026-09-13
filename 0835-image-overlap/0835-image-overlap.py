class Solution(object):
    def largestOverlap(self, img1, img2):
        """
        :type img1: List[List[int]]
        :type img2: List[List[int]]
        :rtype: int
        """
        maxx=0
        n=len(img1)
        a=[]
        b=[]
        for i in range(n):
            for j in range(n):
                if img1[i][j]==1:
                    a.append((i,j))
                if img2[i][j]==1:
                    b.append((i,j))
        d={}
        ans=0
        for x,y in a:
            for p,q in b:
                dx=p-x
                dy=q-y
                key=(dx,dy)
                if key not in d:
                    d[key]=0
                d[key]+=1
                ans=max(ans,d[key])
        return ans
                
        return maxx