# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def rightSideView(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: List[int]
        """
        if not root:
            return []
        res=[]
        q=[root]
        while q:
            res.append(q[-1].val)
            next_q=[]
            for node in q:
                if node.left:
                    next_q.append(node.left)
                if node.right:
                    next_q.append(node.right)
            q=next_q
        return res