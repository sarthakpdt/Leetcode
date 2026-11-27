class Solution(object):
    def maximumSaleItems(self,items,budget):
        n=len(items)
        minprice=min(items[i][1] for i in range(n))

        dp=[-1]*(budget+1)
        dp[0]=0

        for i in range(n):
            factor=items[i][0]
            price=items[i][1]

            count=1

            for j in range(n):
                if (i!=j and items[j][0]%factor==0):
                    count+=1

            for j in range(budget,price-1,-1):
                if (dp[j-price]!=-1):
                    dp[j]=max(dp[j],dp[j-price]+count)

        ans=0

        for i in range(budget+1):
            if (dp[i]!=-1):
                total=dp[i]+(budget-i)//minprice
                ans=max(ans,total)

        return ans