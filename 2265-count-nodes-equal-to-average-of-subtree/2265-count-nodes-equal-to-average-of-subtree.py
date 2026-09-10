# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def averageOfSubtree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.matching=0
        def post(node):
            if not node:
                return 0,0
            lsum,lcount=post(node.left)
            rsum,rcount=post(node.right)
            totals=node.val+lsum+rsum
            totalc=1+lcount+rcount
            if node.val==totals//totalc:
                self.matching+=1
            return totals,totalc
        post(root)
        return self.matching
        