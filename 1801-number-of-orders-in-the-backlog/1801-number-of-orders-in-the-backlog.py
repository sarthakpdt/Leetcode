import heapq
class Solution(object):
    def getNumberOfBacklogOrders(self, orders):
        buys=[]
        sells=[]
        for p, a, t in orders:
            if t==0:
                while a>0 and sells and sells[0][0]<=p:
                    sp, sa=heapq.heappop(sells)
                    if sa<=a:
                        a-=sa
                    else:
                        heapq.heappush(sells, (sp, sa-a))
                        a=0
                if a>0:
                    heapq.heappush(buys, (-p, a))
            else:
                while a>0 and buys and -buys[0][0]>=p:
                    bp, ba=heapq.heappop(buys)
                    if ba<=a:
                        a-=ba
                    else:
                        heapq.heappush(buys, (bp, ba-a))
                        a=0
                if a>0:
                    heapq.heappush(sells, (p, a))
        return sum(a for _, a in buys+sells)%(10**9+7)