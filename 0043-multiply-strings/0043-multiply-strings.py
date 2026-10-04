class Solution(object):
    def multiply(self,num1,num2):
        if num1=="0" or num2=="0":
            return "0"
        len1,len2=len(num1),len(num2)
        result=[0]*(len1+len2)
        for i in range(len1-1,-1,-1):
            for j in range(len2-1,-1,-1):
                mul=(ord(num1[i])-ord('0'))*(ord(num2[j])-ord('0'))
                p1=i+j
                p2=i+j+1
                total_sum=mul+result[p2]
                result[p2]=total_sum%10
                result[p1]+=total_sum//10
        start_idx=0
        while start_idx<len(result) and result[start_idx]==0:
            start_idx+=1
        return "".join(str(digit) for digit in result[start_idx:])
