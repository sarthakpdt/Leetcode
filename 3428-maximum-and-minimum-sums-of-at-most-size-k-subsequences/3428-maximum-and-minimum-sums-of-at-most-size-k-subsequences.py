class Solution(object):
    def minMaxSums(self, nums, k):
        MOD=10**9+7
        nums.sort()
        n=len(nums)
        fact=[1]*(n+1)
        inv=[1]*(n+1)
        for i in range(1, n+1):
            fact[i]=(fact[i-1]*i)%MOD
        inv[n]=pow(fact[n], MOD-2, MOD)
        for i in range(n-1, -1, -1):
            inv[i]=(inv[i+1]*(i+1))%MOD
        def nCr(n, r):
            if r<0 or r>n:
                return 0
            return fact[n]*inv[r]%MOD*inv[n-r]%MOD
        comb_sum=[0]*(n+1)
        for i in range(n+1):
            s=0
            for r in range(k):
                s=(s+nCr(i, r))%MOD
            comb_sum[i]=s
        ans=0
        for i, v in enumerate(nums):
            min_count=comb_sum[n-1-i]
            max_count=comb_sum[i]
            ans=(ans+v*(min_count+max_count))%MOD
        return ans