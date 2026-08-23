class Solution(object):
    def sumGame(self, num):
        """
        :type num: str
        :rtype: bool
        """
        n=len(num)
        leftsum=0
        rightsum=0
        leftq=0
        rightq=0
        for i in range(n//2):
            if num[i]=='?':
                leftq+=1
            else:
                leftsum+=int(num[i])
        for i in range(n//2,n):
            if num[i]=='?':
                rightq+=1
            else:
                rightsum+=int(num[i])
        if (leftq+rightq)%2!=0:
            return True
        if leftsum-rightsum==(rightq-leftq)//2*9:
            return False
        return True