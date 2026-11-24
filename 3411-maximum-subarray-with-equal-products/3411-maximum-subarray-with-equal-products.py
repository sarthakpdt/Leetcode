class Solution(object):
    def maxLength(self,nums):
        n=len(nums)
        ans=0
        for i in range(n):
            prod=1
            g=0
            l=1
            for j in range(i,n):
                prod*=nums[j]
                a=g
                b=nums[j]
                while (b!=0):
                    temp=b
                    b=a%b
                    a=temp
                g=a
                a=l
                b=nums[j]
                while (b!=0):
                    temp=b
                    b=a%b
                    a=temp
                l=(l*nums[j])//a
                if (prod==g*l):
                    ans=max(ans,j-i+1)
        return ans