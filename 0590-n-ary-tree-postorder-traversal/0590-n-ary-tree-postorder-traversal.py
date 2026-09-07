"""
# Definition for a Node.
class Node(object):
	def __init__(self, val: Optional[int] = None, children: Optional[List['Node']] = None):
        self.val = val
        self.children = children
"""

class Solution(object):
    def postorder(self, root):
        """
        :type root: Node
        :rtype: List[int]
        """
        stack=[]
        if (root==None):
            return stack
        for i in root.children:
            stack+=self.postorder(i)
        stack.append(root.val)
        return stack