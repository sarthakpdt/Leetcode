class Solution(object):
    def isLongPressedName(self, name, typed):
        """
        :type name: str
        :type typed: str
        :rtype: bool
        """
        n=len(name)
        m=len(typed)
        i=0
        j=0
        while (j<m):
            if (i<n and name[i]==typed[j]):
                i+=1
                j+=1
            elif (j>0 and typed[j]==typed[j-1]):
                j+=1
            else:
                return False
        return i==n
        