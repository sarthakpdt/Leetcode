class Solution(object):
    def findSubtreeSizes(self,parent,s):
        n=len(parent)
        tree=[[] for i in range(n)]
        for i in range(1,n):
            tree[parent[i]].append(i)
        new_parent=parent[:]
        stacks=[[] for i in range(26)]
        stack=[(0,0)]
        while stack:
            node,state=stack.pop()
            ch=ord(s[node])-ord('a')
            if (state==0):
                if (stacks[ch]):
                    new_parent[node]=stacks[ch][-1]
                stacks[ch].append(node)
                stack.append((node,1))
                for child in reversed(tree[node]):
                    stack.append((child,0))
            else:
                stacks[ch].pop()
        final_tree=[[] for i in range(n)]
        for i in range(1,n):
            final_tree[new_parent[i]].append(i)
        order=[]
        stack=[0]
        while stack:
            node=stack.pop()
            order.append(node)
            for child in final_tree[node]:
                stack.append(child)
        answer=[1]*n
        for i in range(len(order)-1,0,-1):
            node=order[i]
            answer[new_parent[node]]+=answer[node]
        return answer