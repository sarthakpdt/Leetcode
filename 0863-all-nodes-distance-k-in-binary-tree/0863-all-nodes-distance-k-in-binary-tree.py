class Solution(object):
    def distanceK(self,root,target,k):
        parent={}
        stack=[root]
        while stack:
            node=stack.pop()
            if node.left:
                parent[node.left]=node
                stack.append(node.left)
            if node.right:
                parent[node.right]=node
                stack.append(node.right)

        ans=[]
        visited=set()
        stack=[(target,0)]
        visited.add(target)

        while stack:
            node,dist=stack.pop()
            if dist==k:
                ans.append(node.val)
                continue
            if node.left and node.left not in visited:
                visited.add(node.left)
                stack.append((node.left,dist+1))
            if node.right and node.right not in visited:
                visited.add(node.right)
                stack.append((node.right,dist+1))
            if node in parent and parent[node] not in visited:
                visited.add(parent[node])
                stack.append((parent[node],dist+1))
        return ans