from collections import deque
class Solution(object):
    def deepestLeavesSum(self,root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        q=deque([root])
        ans=0
        while q:
            size=len(q)
            ans=0
            for i in range(size):
                node=q.popleft()
                ans+=node.val
                if (node.left):
                    q.append(node.left)
                if (node.right):
                    q.append(node.right)
        return ans 