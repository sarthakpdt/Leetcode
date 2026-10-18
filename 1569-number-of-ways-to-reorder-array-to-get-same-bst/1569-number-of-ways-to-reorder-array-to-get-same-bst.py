class Solution(object):
    def numOfWays(self, nums):
        mod=10**9+7
        n=len(nums)
        comb=[[0]*(n+1) for i in range(n+1)]
        for i in range(n+1):
            comb[i][0]=1
            comb[i][i]=1
            for j in range(1,i):
                comb[i][j]=(comb[i-1][j-1]+comb[i-1][j])%mod
        def solve(arr):
            if len(arr)<=2:
                return 1
            root=arr[0]
            left=[]
            right=[]
            for i in range(1,len(arr)):
                if arr[i]<root:
                    left.append(arr[i])
                else:
                    right.append(arr[i])
            ways=comb[len(arr)-1][len(left)]
            ways=(ways*solve(left))%mod
            ways=(ways*solve(right))%mod
            return ways
        return (solve(nums)-1)%mod