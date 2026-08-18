class Solution(object):
    def largestRectangleArea(self,heights):
        stack=[]
        maxx=0
        n=len(heights)
        for i in range(n):
            while stack and heights[stack[-1]]>heights[i]:
                height=heights[stack.pop()]
                width=i if not stack else i-stack[-1]-1
                maxx=max(maxx,height*width)
            stack.append(i)
        while stack:
            height=heights[stack.pop()]
            width=n if not stack else n-stack[-1]-1
            maxx=max(maxx,height*width)
        return maxx