class Solution(object):
    def removeOuterParentheses(self, s):
        """
        :type s: str
        :rtype: str
        """
        res=[]
        op=0
        for i in s:
            if i=="(":
                if op>0:
                    res.append(i)
                op+=1
            else:
                op-=1
                if op>0:
                    res.append(i)
        return "".join(res)