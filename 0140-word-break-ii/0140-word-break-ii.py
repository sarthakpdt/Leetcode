class Solution(object):
    def wordBreak(self, s, wordDict):
        words=set(wordDict)
        memo={}
        def dfs(idx):
            if idx in memo:
                return memo[idx]
            if idx==len(s):
                return [""]
            res=[]
            for i in range(idx+1, len(s)+1):
                w=s[idx:i]
                if w in words:
                    for sub in dfs(i):
                        res.append(w+(" "+sub if sub else ""))
            memo[idx]=res
            return res
        return dfs(0)