import heapq
class Solution(object):
    def busiestServers(self,k,arrival,load):
        """
        :type k: int
        :type arrival: List[int]
        :type load: List[int]
        :rtype: List[int]
        """
        free=list(range(k))
        heapq.heapify(free)
        handled=[]
        busy=[]
        for i,(t,d) in enumerate(zip(arrival,load)):
            while busy and busy[0][0]<=t:
                server=heapq.heappop(busy)[1]
                heapq.heappush(free,i+(server-i)%k)
            if free:
                x=heapq.heappop(free)%k
                heapq.heappush(busy,(t+d,x))
                handled.append(x)
        count=[0]*k
        for i in handled:
            count[i]+=1
        maxi=max(count)
        ans=[]
        for i in range(k):
            if count[i]==maxi:
                ans.append(i)
        return ans