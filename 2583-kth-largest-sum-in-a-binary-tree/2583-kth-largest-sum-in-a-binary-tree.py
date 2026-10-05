class Solution(object):
    def kthLargestLevelSum(self, root, k):
        if not root:
            return -1
        q=[root]
        sums=[]
        while q:
            sums.append(sum(node.val for node in q))
            next_q=[]
            for node in q:
                if node.left:
                    next_q.append(node.left)
                if node.right:
                    next_q.append(node.right)
            q=next_q
        if len(sums)<k:
            return -1
        sums.sort(reverse=True)
        return sums[k-1]