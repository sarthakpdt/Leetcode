class BIT(object):
    def __init__(self, n):
        self.tree=[0]*(n+1)
    def update(self, idx, val):
        while idx<len(self.tree):
            self.tree[idx]+=val
            idx+=idx&-idx
    def query(self, idx):
        s=0
        while idx>0:
            s+=self.tree[idx]
            idx-=idx&-idx
        return s
class Solution(object):
    def minInversionCount(self, nums, k):
        vals=sorted(list(set(nums)))
        ranks={v: i+1 for i, v in enumerate(vals)}
        arr=[ranks[x] for x in nums]
        m=len(vals)
        bit=BIT(m)
        cur=0
        for i in range(k):
            v=arr[i]
            cur+=i-bit.query(v)
            bit.update(v, 1)
        ans=cur
        for i in range(k, len(nums)):
            rem=arr[i-k]
            cur-=bit.query(rem-1)
            bit.update(rem, -1)
            add=arr[i]
            cur+=k-1-bit.query(add)
            bit.update(add, 1)
            if cur<ans:
                ans=cur
        return ans