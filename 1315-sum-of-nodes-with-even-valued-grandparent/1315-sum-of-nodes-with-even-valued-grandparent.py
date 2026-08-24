# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def sumEvenGrandparent(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        if root is None:
            return 0
        summ=0
        if root.val%2==0:
            if root.left:
                if root.left.left:
                    summ+=root.left.left.val
                if root.left.right:
                    summ+=root.left.right.val
            if root.right:
                if root.right.left:
                    summ+=root.right.left.val
                if root.right.right:
                    summ+=root.right.right.val
        summ+=self.sumEvenGrandparent(root.left)
        summ+=self.sumEvenGrandparent(root.right)
        return summ
        