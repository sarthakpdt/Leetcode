class Solution(object):
    def getMinSwaps(self, num, k):
        """
        :type num: str
        :type k: int
        :rtype: int
        """
        def permutation(arr):
            n=len(arr)
            i=n-2
            while i>=0 and arr[i]>=arr[i+1]:
                i-=1
            if i>=0:
                j=n-1
                while arr[j]<=arr[i]:
                    j-=1
                arr[i],arr[j]=arr[j],arr[i]
            arr[i+1:]=reversed(arr[i+1:])
        target=list(num)
        for i in range(k):
            permutation(target)
        ori=list(num)   
        swap=0
        n=len(ori)
        for i in range(n):
            if ori[i]!=target[i]:
                j=i
                while ori[j]!=target[i]:
                    j+=1
                while j>i:
                    ori[j],ori[j-1]=(ori[j-1],ori[j])
                    swap+=1
                    j-=1
        return swap