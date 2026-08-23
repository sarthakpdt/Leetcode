class Solution(object):
    def getStrongest(self, arr, k):
        """
        :type arr: List[int]
        :type k: int
        :rtype: List[int]
        """
        arr.sort()
        n=len(arr)
        m=((n-1)//2)
        mid=arr[m]
        left=0
        right=n-1
        res=[]
        while (len(res)<k):
            if (abs(arr[left]-mid)>abs(arr[right]-mid)):
                res.append(arr[left])
                left+=1
            elif (abs(arr[left]-mid)<abs(arr[right]-mid)):
                res.append(arr[right])
                right-=1
            else:
                if (arr[left]>arr[right]):
                    res.append(arr[left])
                    left+=1
                else:
                    res.append(arr[right])
                    right-=1
        return res
