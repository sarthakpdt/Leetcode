class Solution(object):
    def maxPathSum(self,root):
        self.ans=root.val
        def dfs(node):
            if not node:
                return 0
            left=max(0,dfs(node.left))
            right=max(0,dfs(node.right))
            self.ans=max(self.ans,left+right+node.val)
            return node.val+max(left,right)
        dfs(root)
        return self.ans