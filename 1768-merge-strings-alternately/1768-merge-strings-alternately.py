class Solution(object):
    def mergeAlternately(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: str
        """
        n=len(word1)
        m=len(word2)
        res=[]
        if(n==m):
            i=0
            j=0
            while i<n and j<m:
                res.append(word1[i])
                res.append(word2[j])
                i+=1
                j+=1
            return "".join(res)
        elif (n>m):
            i=0
            j=0
            while i<n and j<m:
                res.append(word1[i])
                res.append(word2[j])
                i+=1
                j+=1
            res.append(word1[i:])
            return "".join(res)
        else:
            i=0
            j=0
            while i<n and j<m:
                res.append(word1[i])
                res.append(word2[j])
                i+=1
                j+=1
            res.append(word2[j:])
            return "".join(res)
