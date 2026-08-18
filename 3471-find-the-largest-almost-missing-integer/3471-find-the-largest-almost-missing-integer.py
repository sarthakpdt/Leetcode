class Solution(object):
    def largestInteger(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :type rtype: int
        """
        subarray_counts={}
        n=len(nums)
        for i in range(n-k+1):
            subarray=nums[i:i+k]
            unique_elements=set(subarray)
            for num in unique_elements:
                subarray_counts[num]=subarray_counts.get(num,0)+1
        largest_almost_missing=-1
        for num, count in subarray_counts.items():
            if count==1:
                if num>largest_almost_missing:
                    largest_almost_missing=num
        return largest_almost_missing
