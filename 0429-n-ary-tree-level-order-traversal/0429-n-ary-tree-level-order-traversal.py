class Solution(object):
    def levelOrder(self, root):
        if not root:
            return []
        ans=[]
        q=[root]
        while q:
            ans.append([node.val for node in q])
            next_q=[]
            for node in q:
                if node.children:
                    next_q.extend(node.children)
            q=next_q
        return ans