class Solution(object):
    def backspaceCompare(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        stacks=[]
        stackt=[]
        for i in s:
            if i=="#":
                if stacks:
                    stacks.pop()
            else:
                stacks.append(i)
        for j in t:
            if j=="#":
                if stackt:
                    stackt.pop()
            else:
                stackt.append(j)
        if stacks==stackt:
            return True
        else:
            return False
        