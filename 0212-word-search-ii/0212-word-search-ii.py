class Solution(object):
    def findWords(self,board,words):
        trie={}

        for word in words:
            node=trie

            for ch in word:
                if ch not in node:
                    node[ch]={}
                node=node[ch]

            node["#"]=word

        m=len(board)
        n=len(board[0])
        ans=[]

        def dfs(i,j,node):
            ch=board[i][j]

            if ch not in node:
                return

            node=node[ch]

            if "#" in node:
                ans.append(node["#"])
                del node["#"]

            board[i][j]="#"

            if i>0 and board[i-1][j]!="#":
                dfs(i-1,j,node)

            if i<m-1 and board[i+1][j]!="#":
                dfs(i+1,j,node)

            if j>0 and board[i][j-1]!="#":
                dfs(i,j-1,node)

            if j<n-1 and board[i][j+1]!="#":
                dfs(i,j+1,node)

            board[i][j]=ch

        for i in range(m):
            for j in range(n):
                dfs(i,j,trie)

        return ans