class Solution(object):
    def minDays(self,bloomDay,m,k):
        n=len(bloomDay)
        if m*k>n:
            return -1
        def cake(day):
            boq=0
            flower=0
            for i in bloomDay:
                if i<=day:
                    flower+=1
                    if flower>=k:
                        boq+=1
                        flower=0
                else:
                    flower=0
                if boq>=m:
                    return True
            return False
        low=min(bloomDay)
        high=max(bloomDay)
        ans=high
        while low<=high:
            mid=(low+high)//2
            if cake(mid):
                ans=mid
                high=mid-1
            else:
                low=mid+1
        return ans