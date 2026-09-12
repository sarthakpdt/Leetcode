class Solution(object):
    def maximumSumOfHeights(self,heights):
        n=len(heights)
        l=[0]*n
        r=[0]*n
        st=[]
        for i in range(n):
            while st and heights[st[-1]]>heights[i]:
                st.pop()
            if st:
                j=st[-1]
                l[i]=l[j]+(i-j)*heights[i]
            else:
                l[i]=(i+1)*heights[i]
            st.append(i)
        st=[]
        for i in range(n-1,-1,-1):
            while st and heights[st[-1]]>heights[i]:
                st.pop()
            if st:
                j=st[-1]
                r[i]=r[j]+(j-i)*heights[i]
            else:
                r[i]=(n-i)*heights[i]
            st.append(i)
        ans=0
        for i in range(n):
            ans=max(ans,l[i]+r[i]-heights[i])
        return ans