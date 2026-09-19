import heapq

class Solution(object):
    def reorganizeString(self,s):
        freq=[0]*26

        for ch in s:
            freq[ord(ch)-ord('a')]+=1

        q=[]

        for i in range(26):
            if freq[i]>0:
                heapq.heappush(q,(-freq[i],chr(i+ord('a'))))

        ans=[]
        prev=None

        while q:
            cnt,ch=heapq.heappop(q)

            if ch==prev:
                if not q:
                    return ""

                cnt2,ch2=heapq.heappop(q)
                ans.append(ch2)
                prev=ch2
                cnt2+=1

                if cnt2<0:
                    heapq.heappush(q,(cnt2,ch2))

                heapq.heappush(q,(cnt,ch))
            else:
                ans.append(ch)
                prev=ch
                cnt+=1

                if cnt<0:
                    heapq.heappush(q,(cnt,ch))

        return "".join(ans)