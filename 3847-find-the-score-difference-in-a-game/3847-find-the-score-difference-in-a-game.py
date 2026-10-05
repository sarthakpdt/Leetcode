class Solution(object):
    def scoreDifference(self, nums):
        a=0
        b=0
        active=0
        for i, v in enumerate(nums):
            if v%2!=0:
                active^=1
            if (i+1)%6==0:
                active^=1
            if active==0:
                a+=v
            else:
                b+=v
        return a-b