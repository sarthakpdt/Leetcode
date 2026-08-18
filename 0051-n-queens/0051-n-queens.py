class Solution(object):
    def solveNQueens(self,n):
        ans=[]
        board=[["."]*n for i in range(n)]
        def safe(row,col):
            for i in range(row):
                if board[i][col]=="Q":
                    return False
            i=row-1
            j=col-1
            while i>=0 and j>=0:
                if board[i][j]=="Q":
                    return False
                i-=1
                j-=1
            i=row-1
            j=col+1
            while i>=0 and j<n:
                if board[i][j]=="Q":
                    return False
                i-=1
                j+=1
            return True
        def solve(row):
            if row==n:
                arr=[]
                for i in range(n):
                    arr.append("".join(board[i]))
                ans.append(arr)
                return
            for col in range(n):
                if safe(row,col):
                    board[row][col]="Q"
                    solve(row+1)
                    board[row][col]="."
        solve(0)
        return ans