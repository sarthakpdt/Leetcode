# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def findMode(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: List[int]
        """
        freq={}
        def dfs(root):
            if root is None:
                return 0
            freq[root.val]=freq.get(root.val,0)+1
            dfs(root.left)
            dfs(root.right)
        dfs(root)
        maxx=max(freq.values())
        res=[]
        for key in freq:
            if freq[key]==maxx:
                res.append(key)
        return res
        