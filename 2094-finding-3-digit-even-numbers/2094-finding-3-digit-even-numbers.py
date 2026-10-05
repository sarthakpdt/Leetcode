from collections import Counter
class Solution(object):
    def findEvenNumbers(self, digits):
        cnt=Counter(digits)
        res=[]
        for num in range(100,1000,2):
            d1=num//100
            d2=(num//10)%10
            d3=num%10
            cur_cnt=Counter([d1,d2,d3])
            if all(cnt[d]>=cur_cnt[d] for d in cur_cnt):
                res.append(num)
        return res