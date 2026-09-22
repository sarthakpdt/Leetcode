class Solution(object):
    def superPow(self, a, b):
        MOD=1337
        def pow_mod(x, y):
            x%=MOD
            res=1
            while y>0:
                if y%2==1:
                    res=(res*x)%MOD
                x=(x*x)%MOD
                y//=2
            return res
        ans=1
        a%=MOD
        for digit in b:
            ans=(pow_mod(ans, 10)*pow_mod(a, digit))%MOD
        return ans