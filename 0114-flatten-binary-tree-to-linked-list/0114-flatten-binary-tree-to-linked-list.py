# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def flatten(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: None Do not return anything, modify root in-place instead.
        """
        if root==None:
            return 
        a=[]
        def dfs(root):
            if root==None:
                return 
            a.append(root)
            dfs(root.left)
            dfs(root.right)
        dfs(root)
        for i in range(len(a)-1):
            a[i].left=None
            a[i].right=a[i+1]
        a[-1].left=None
        a[-1].right=None