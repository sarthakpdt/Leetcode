# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def insertGreatestCommonDivisors(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        curr=head
        while curr and curr.next:
            nxt=curr.next
            a,b=curr.val,nxt.val
            while(b!=0):
                a,b=b,a%b
            gcd=a
            new=ListNode(gcd)
            curr.next=new
            new.next=nxt
            curr=nxt
        return head
