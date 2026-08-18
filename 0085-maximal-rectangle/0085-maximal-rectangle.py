class Solution(object):
    def maximalRectangle(self,matrix):
        if not matrix or not matrix[0]:
            return 0
        row=len(matrix)
        col=len(matrix[0])
        maxx=0
        height=[0]*col
        for i in range(row):
            for j in range(col):
                if matrix[i][j]=="1":
                    height[j]+=1
                else:
                    height[j]=0
            maxx=max(maxx,self.area(height))
        return maxx

    def area(self,height):
        stack=[]
        maxx=0
        n=len(height)
        for i in range(n+1):
            curr=height[i] if i<n else 0
            while stack and height[stack[-1]]>=curr:
                heights=height[stack.pop()]
                width=i if not stack else i-stack[-1]-1
                maxx=max(maxx,heights*width)
            stack.append(i)
        return maxx