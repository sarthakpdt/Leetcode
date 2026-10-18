class Solution(object):
    def chalkReplacer(self, chalk, k):
        k %= sum(chalk)
        for i in range(len(chalk)):
            if k < chalk[i]:
                return i
            k -= chalk[i]