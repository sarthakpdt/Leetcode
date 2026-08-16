class Solution(object):
    def stoneGameIX(self, stones):
        """
        :type stones: List[int]
        :rtype: bool
        """
        count0=0
        count1=0
        count2=0
        for i in stones:
            if (i%3==0):
                count0+=1
            elif (i%3==1):
                count1+=1
            else:
                count2+=1
        if count0%2==0:
            return count1>0 and count2>0
        return abs(count1-count2)>2
