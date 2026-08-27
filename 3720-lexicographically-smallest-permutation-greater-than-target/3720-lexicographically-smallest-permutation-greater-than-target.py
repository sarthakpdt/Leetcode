class Solution(object):
    def lexGreaterPermutation(self,s,target):
        """
        :type s: str
        :type target: str
        :rtype: str
        """
        count=[0]*26
        for ch in s:
            count[ord(ch)-97]+=1
        ans=""
        possible=[]
        for i in range(len(s)):
            x=ord(target[i])-97
            for j in range(x+1,26):
                if count[j]>0:
                    temp=ans+chr(j+97)
                    count[j]-=1
                    for k in range(26):
                        temp+=chr(k+97)*count[k]
                    possible.append(temp)
                    count[j]+=1
                    break
            if count[x]==0:
                break
            ans+=target[i]
            count[x]-=1
        if not possible:
            return ""
        return min(possible)