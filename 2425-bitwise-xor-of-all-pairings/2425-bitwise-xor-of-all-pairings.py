class Solution(object):
    def xorAllNums(self, nums1, nums2):
        ans=0
        if len(nums2)%2!=0:
            for x in nums1:
                ans^=x
        if len(nums1)%2!=0:
            for x in nums2:
                ans^=x
        return ans