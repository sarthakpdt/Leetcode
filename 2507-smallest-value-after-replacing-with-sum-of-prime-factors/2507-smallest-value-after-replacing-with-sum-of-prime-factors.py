class Solution(object):
    def smallestValue(self, n):
        while True:
            curr=n
            s=0
            d=2
            temp=curr
            while d*d<=temp:
                while temp%d==0:
                    s+=d
                    temp//=d
                d+=1
            if temp>1:
                s+=temp
            if s==curr:
                return curr
            n=s