class Solution(object):
    def minSumSquareDiff(self, nums1, nums2, k1, k2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k1: int
        :type k2: int
        :rtype: int
        """
        diff=[]
        for i in range(len(nums1)):
            diff.append(abs(nums1[i]-nums2[i]))
        k=k1+k2
        if (sum(diff)<=k):
            return 0
        low=0
        high=max(diff)
        while (low<high):
            mid=(low+high)//2
            total=0
            for x in diff:
                if (x>mid):
                    total+=x-mid
            if (total<=k):
                high=mid
            else:
                low=mid+1
        ans=0
        remain=k
        for x in diff:
            if (x>low):
                remain-=x-low
                ans+=low*low
            else:
                ans+=x*x
        for x in diff:
            if (remain>0 and x>=low):
                ans-=low*low-(low-1)*(low-1)
                remain-=1
        return ans