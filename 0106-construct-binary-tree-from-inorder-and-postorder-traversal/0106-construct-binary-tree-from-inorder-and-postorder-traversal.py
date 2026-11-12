# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: Optional[TreeNode]
        """
        if (len(inorder)==0):
            return None
        root=TreeNode(postorder[-1])
        i=inorder.index(postorder[-1])
        root.left=self.buildTree(inorder[:i],postorder[:i])
        root.right=self.buildTree(inorder[i+1:],postorder[i:-1])
        return root