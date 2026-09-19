class Solution(object):
    def getAverages(self,nums,k):
        n=len(nums)
        ans=[-1]*n

        if 2*k+1>n:
            return ans

        size=2*k+1
        s=sum(nums[:size])

        ans[k]=s//size

        for i in range(k+1,n-k):
            s-=nums[i-k-1]
            s+=nums[i+k]
            ans[i]=s//size

        return ans