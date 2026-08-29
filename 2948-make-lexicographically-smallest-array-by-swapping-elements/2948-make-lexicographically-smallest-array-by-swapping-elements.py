class Solution(object):
    def lexicographicallySmallestArray(self, nums, limit):
        """
        :type nums: List[int]
        :type limit: int
        :rtype: List[int]
        """
        n=len(nums)
        pairs=[]
        for i in range(n):
            pairs.append((nums[i],i))
        pairs.sort()
        i=0
        while i<n:
            j=i
            while j<n-1 and pairs[j+1][0]-pairs[j][0]<=limit:
                j+=1
            values=[]
            ind=[]
            for k in range(i,j+1):
                values.append(pairs[k][0])
                ind.append(pairs[k][1])
            ind.sort()
            for k in range(len(ind)):
                nums[ind[k]]=values[k]
            i=j+1
        return nums
                



        