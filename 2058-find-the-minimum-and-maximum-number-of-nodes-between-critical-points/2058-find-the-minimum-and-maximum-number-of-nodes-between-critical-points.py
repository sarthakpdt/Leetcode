class Solution(object):
    def nodesBetweenCriticalPoints(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: List[int]
        """
        prev=head
        curr=head.next
        pos=1
        first=-1
        last=-1
        minn=1000000
        while curr.next!=None:
            nxt=curr.next
            if ((curr.val>prev.val and curr.val>nxt.val) or
                (curr.val<prev.val and curr.val<nxt.val)):
                if first==-1:
                    first=pos
                else:
                    minn=min(minn,pos-last)
                last=pos
            prev=curr
            curr=nxt
            pos+=1
        if first==-1 or first==last:
            return [-1,-1]
        maxx=last-first
        return [minn,maxx]