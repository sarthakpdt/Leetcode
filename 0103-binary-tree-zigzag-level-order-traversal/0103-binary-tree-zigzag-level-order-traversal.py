class Solution(object):
    def zigzagLevelOrder(self,root):
        if not root:
            return []
        q=[root]
        ans=[]
        left=True
        while q:
            size=len(q)
            row=[]
            for i in range(size):
                node=q.pop(0)
                row.append(node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            if not left:
                row.reverse()
            ans.append(row)
            left=not left
        return ans