import heapq
class Solution(object):
    def assignTasks(self, servers, tasks):
        free=[(servers[i],i) for i in range(len(servers))]
        heapq.heapify(free)
        busy=[]
        ans=[]
        t=0
        for i in range(len(tasks)):
            t=max(t,i)
            if not free:
                t=busy[0][0]
            while busy and busy[0][0]<=t:
                free_t,w,idx=heapq.heappop(busy)
                heapq.heappush(free,(w,idx))
            w,idx=heapq.heappop(free)
            ans.append(idx)
            heapq.heappush(busy,(t+tasks[i],w,idx))
        return ans