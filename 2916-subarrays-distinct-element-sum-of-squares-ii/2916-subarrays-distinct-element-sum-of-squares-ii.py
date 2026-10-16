from collections import defaultdict
class BIT:
    def __init__(self,n):
        self.size=n
        self.tree1=defaultdict(int)
        self.tree2=defaultdict(int)
    def lowbit(self,index):
        return index&-index
    def add(self,left,right,delta):
        self._add(left,delta)
        self._add(right+1,-delta)
    def query(self,left,right):
        return self._query(right)-self._query(left-1)
    def _add(self,index,delta):
        index+=1
        rawIndex=index
        while index<=self.size:
            self.tree1[index]+=delta
            self.tree2[index]+=(rawIndex-1)*delta
            index+=self.lowbit(index)
    def _query(self,index):
        index+=1
        if index>self.size:
            index=self.size
        rawIndex=index
        res=0
        while index>0:
            res+=rawIndex*self.tree1[index]-self.tree2[index]
            index-=self.lowbit(index)
        return res
class Solution(object):
    def sumCounts(self, nums):
        n=len(nums)
        res=0
        cur=0
        bit=BIT(n+10)
        seen={}
        mod=10**9+7
        for i,a in enumerate(nums):
            j=seen.get(a,-1)+1
            cur=(cur+bit.query(j,i)*2+i-j+1)%mod
            res=(res+cur)%mod
            bit.add(j,i,1)
            seen[a]=i
        return res