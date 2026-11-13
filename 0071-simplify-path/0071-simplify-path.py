class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        stack=[]
        arr=path.split('/')
        for i in arr:
            if (i=='' or i=='.'):
                continue
            elif (i=='..'):
                if stack:
                    stack.pop()
            else:
                stack.append(i)
        return '/'+'/'.join(stack)
