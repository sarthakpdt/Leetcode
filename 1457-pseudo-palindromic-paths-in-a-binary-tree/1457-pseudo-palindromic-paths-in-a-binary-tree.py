class Solution(object):
    def pseudoPalindromicPaths(self,root):
        def dfs(node,path_mask):
            if not node:
                return 0
            path_mask^=(1<<node.val)
            if not node.left and not node.right:
                return 1 if(path_mask&(path_mask-1))==0 else 0
            return dfs(node.left,path_mask)+dfs(node.right,path_mask)
        return dfs(root,0)