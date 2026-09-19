class Solution(object):
    def convert(self,s,numRows):
        if numRows==1 or numRows>=len(s):
            return s

        a=[""]*numRows
        r=0
        d=1

        for ch in s:
            a[r]+=ch

            if r==0:
                d=1
            elif r==numRows-1:
                d=-1

            r+=d

        return "".join(a)