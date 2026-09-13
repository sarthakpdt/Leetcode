# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def balanceBST(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: Optional[TreeNode]
        """
        a=[]
        def inorder(root):
            if root==None:
                return 
            inorder(root.left)
            a.append(root)
            inorder(root.right)
        inorder(root)
        def build(l,r):
            if l>r:
                return None
            mid=(l+r)//2
            root=a[mid]
            root.left=build(l,mid-1)
            root.right=build(mid+1,r)
            return root
        return build(0,len(a)-1)