class Solution(object):
    def centeredSubarrays(self,nums):
        n=len(nums)
        ans=0

        for i in range(n):
            s=0
            a=set()

            for j in range(i,n):
                s+=nums[j]
                a.add(nums[j])

                if s in a:
                    ans+=1

        return ans