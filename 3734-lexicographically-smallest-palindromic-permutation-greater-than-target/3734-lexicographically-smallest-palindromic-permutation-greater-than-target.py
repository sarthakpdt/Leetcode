class Solution(object):
    def lexPalindromicPermutation(self, s, target):
        """
        :type s: str
        :type target: str
        :rtype: str
        """
        count=[0]*26
        for ch in s:
            count[ord(ch)-97]+=1
        odd=0
        middle=""
        for i in range(26):
            if count[i]%2!=0:
                odd+=1
                middle=chr(i+97)
        if odd>1:
            return ""
        halfcount=[0]*26
        for i in range(26):
            halfcount[i]=count[i]//2
        h=len(s)//2
        prefix=""
        candidates=[]
        for i in range(h):
            x=ord(target[i])-97
            for j in range(x+1,26):
                if halfcount[j]>0:
                    temp=prefix+chr(j+97)
                    halfcount[j]-=1
                    for k in range(26):
                        temp+=chr(k+97)*halfcount[k]
                    candidates.append(temp)
                    halfcount[j]+=1
                    break
            if halfcount[x]==0:
                break
            prefix+=target[i]
            halfcount[x]-=1
        if len(prefix)==h:
            left=prefix
            if middle:
                ans=left+middle+left[::-1]
            else:
                ans=left+left[::-1]
            if ans>target:
                candidates.append(left)
        if not candidates:
            return ""
        left=min(candidates)
        if middle:
            return left+middle+left[::-1]
        return left+left[::-1]