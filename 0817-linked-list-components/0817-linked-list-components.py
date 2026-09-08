# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def numComponents(self, head, nums):
        """
        :type head: Optional[ListNode]
        :type nums: List[int]
        :rtype: int
        """
        num=set(nums)
        curr=head
        count=0
        while curr:
            if curr.val in num and (curr.next is None or curr.next.val not in num):
                count+=1
            curr=curr.next
        return count