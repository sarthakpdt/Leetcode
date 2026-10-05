class FindElements(object):
    def __init__(self, root):
        self.vals=set()
        if root:
            root.val=0
            q=[root]
            while q:
                node=q.pop()
                self.vals.add(node.val)
                if node.left:
                    node.left.val=2*node.val+1
                    q.append(node.left)
                if node.right:
                    node.right.val=2*node.val+2
                    q.append(node.right)
    def find(self, target):
        return target in self.vals