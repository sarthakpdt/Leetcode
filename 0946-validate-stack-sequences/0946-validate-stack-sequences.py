class Solution(object):
    def validateStackSequences(self,pushed,popped):
        stack=[]
        j=0
        for i in pushed:
            stack.append(i)
            while stack and stack[-1]==popped[j]:
                stack.pop()
                j+=1
                if j==len(popped):
                    break
        return len(stack)==0