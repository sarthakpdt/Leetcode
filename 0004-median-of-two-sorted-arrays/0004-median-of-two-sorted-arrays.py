class Solution(object):
    def findMedianSortedArrays(self,nums1,nums2):
        if len(nums1)>len(nums2):
            return self.findMedianSortedArrays(nums2,nums1)
        n=len(nums1)
        m=len(nums2)
        low=0
        high=n
        total=(n+m+1)//2
        while low<=high:
            mid1=(low+high)//2
            mid2=total-mid1
            lefta=float('-inf') if mid1==0 else nums1[mid1-1]
            righta=float('inf') if mid1==n else nums1[mid1]
            leftb=float('-inf') if mid2==0 else nums2[mid2-1]
            rightb=float('inf') if mid2==m else nums2[mid2]
            if lefta<=rightb and leftb<=righta:
                if (n+m)%2==1:
                    return max(lefta,leftb)
                return (max(lefta,leftb)+min(righta,rightb))/2.0
            if lefta>rightb:
                high=mid1-1
            else:
                low=mid1+1
        return 0.0