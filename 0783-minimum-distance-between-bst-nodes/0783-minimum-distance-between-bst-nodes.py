# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def minDiffInBST(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        val=[]
        def inorder(node):
            if not node:
                return 
            inorder(node.left)
            val.append(node.val)
            inorder(node.right)
        inorder(root)
        minn=float("inf")
        for i in range(1,len(val)):
            minn=min(minn,val[i]-val[i-1])
        return minn