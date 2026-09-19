class Solution(object):
    def numOfUnplacedFruits(self,fruits,baskets):
        n=len(fruits)
        ans=0

        for x in fruits:
            for j in range(n):
                if baskets[j]>=x:
                    baskets[j]=-1
                    break
            else:
                ans+=1

        return ans