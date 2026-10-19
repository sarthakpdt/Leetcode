class Solution(object):

    def countValidSubarrays(self, nums, x):
        n=len(nums)
        sx=str(x)
        ans=0
        for i in range(n):
            s=0
            for j in range(i,n):
                s+=nums[j]
                st=str(s)
                if st[0]==sx and st[-1]==sx:
                    ans+=1
        return ans