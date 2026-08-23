class Solution(object):
    def findClosestElements(self, arr, k, x):
        """
        :type arr: List[int]
        :type k: int
        :type x: int
        :rtype: List[int]
        """
        n=len(arr)
        left=0
        right=n-1
        while right-left+1>k:
            if abs(arr[left]-x)>abs(arr[right]-x):
                left+=1
            else:
                right-=1
        return arr[left:right+1]