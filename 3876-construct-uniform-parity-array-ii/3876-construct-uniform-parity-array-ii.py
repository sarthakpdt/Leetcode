class Solution(object):
    def uniformArray(self, nums1):
        minn=min(nums1)
        if minn%2!=0:
            return True
        for i in nums1:
            if i%2!=0:
                return False
        return True