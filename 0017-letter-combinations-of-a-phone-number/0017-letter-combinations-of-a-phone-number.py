class Solution(object):
    def letterCombinations(self,digits):
        if not digits:
            return []
        keypad=["","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"]
        res=[]
        curr=""
        def backtrack(index):
            if index==len(digits):
                res.append(curr)
                return
            letters=keypad[int(digits[index])]
            for ch in letters:
                backtrack(index+1)
        def solve(index,curr):
            if index==len(digits):
                res.append(curr)
                return
            letters=keypad[int(digits[index])]
            for ch in letters:
                solve(index+1,curr+ch)
        solve(0,"")
        return res