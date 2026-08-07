class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """

        left=0
        right=len(height)-1
        lmax=0
        rmax=0
        total=0
        while(left<right):
            if (height[left]<=height[right]):
                if (height[left]>=lmax):
                    lmax=height[left]
                else:
                    total+=lmax-height[left]
                left+=1
            else:
                if (height[right]>=rmax):
                    rmax=height[right]
                else:
                    total+=rmax-height[right]
                right-=1
        return total

        
        