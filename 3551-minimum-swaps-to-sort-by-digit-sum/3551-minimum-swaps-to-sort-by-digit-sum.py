class Solution(object):
    def minSwaps(self, nums):
        n=len(nums)
        lst=[]
        for i in range(n):
            num=nums[i]
            b=0
            while num>0:
                b+=num%10
                num=num//10
            lst.append((b,nums[i],i))
        lst.sort()
        arr=[]
        for i in range(n):
            arr.append(lst[i][1])
        pos={}
        for i in range(n):
            pos[nums[i]]=i
        count=0
        for i in range(n):
            if (nums[i]!=arr[i]):
                j=pos[arr[i]]
                pos[nums[i]]=j
                pos[nums[j]]=i
                nums[i],nums[j]=nums[j],nums[i]
                count+=1
        return count