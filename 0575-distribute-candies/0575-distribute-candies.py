class Solution(object):
    def distributeCandies(self,candyType):
        n=len(candyType)
        unique=len(set(candyType))
        return min(n//2,unique)