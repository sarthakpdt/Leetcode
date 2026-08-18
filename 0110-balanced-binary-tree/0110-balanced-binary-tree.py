class Solution(object):
    def isBalanced(self,root):
        def check(root):
            if not root:
                return 0
            lefth=check(root.left)
            if lefth==-1:
                return -1
            righth=check(root.right)
            if righth==-1:
                return -1
            if abs(lefth-righth)>1:
                return -1
            return 1+max(lefth,righth)
        return check(root)!=-1