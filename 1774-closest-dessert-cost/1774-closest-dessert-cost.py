class Solution(object):
    def closestCost(self,baseCosts,toppingCosts,target):
        ans=[baseCosts[0]]

        def dfs(i,cost):
            if abs(cost-target)<abs(ans[0]-target) or (abs(cost-target)==abs(ans[0]-target) and cost<ans[0]):
                ans[0]=cost

            if i==len(toppingCosts):
                return

            for x in range(3):
                dfs(i+1,cost+x*toppingCosts[i])

        for x in baseCosts:
            dfs(0,x)

        return ans[0]