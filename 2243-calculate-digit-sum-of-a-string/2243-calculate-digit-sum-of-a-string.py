class Solution(object):
    def digitSum(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        while (len(s)>k):
            lst=[]
            for i in range(0,len(s),k):
                lst.append(s[i:i+k])
            summ=[]
            for i in lst:
                digitsum=0
                for j in i:
                    digitsum+=int(j)
                summ.append(str(digitsum))
            comb="".join(summ)
            s=comb
        return s