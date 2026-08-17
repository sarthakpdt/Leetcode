class Solution:
    def reinitializePermutation(self,n:int)->int:
        if n==2:
            return 1
        pos=1
        count=0
        while True:
            pos=(2*pos)%(n-1)
            count+=1
            if pos==1:
                break
        return count