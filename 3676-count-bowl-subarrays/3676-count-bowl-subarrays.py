class Solution(object):
    def bowlSubarrays(self, nums):
        n = len(nums)
        next_greater = [n] * n
        prev_greater = [-1] * n
        stack = []
        for i in range(n):
            while stack and nums[stack[-1]] < nums[i]:
                next_greater[stack.pop()] = i
            if stack:
                prev_greater[i] = stack[-1]
            stack.append(i)
        bowl_count = 0
        for m in range(n):
            if prev_greater[m] != -1 and next_greater[m] != n:
                bowl_count += 1
        return bowl_count
