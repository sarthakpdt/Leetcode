from fractions import gcd


class Solution(object):

    def maxValidSplits(self, nums):
        n = len(nums)
        pref = [0] * n
        suff = [0] * n
        p = 0
        for i in range(n):
            p = gcd(p, nums[i])
            pref[i] = p
        s = 0
        for i in range(n - 1, -1, -1):
            s = gcd(s, nums[i])
            suff[i] = s

        ans = 0
        for i in range(n - 1):
            if pref[i] == suff[i + 1]:
                ans += 1

        cand = {0, n - 1}
        cur = pref[0]
        for i in range(n):
            if pref[i] != cur:
                cand.add(i - 1)
                cand.add(i)
                cur = pref[i]

        cur = suff[-1]
        for i in range(n - 1, -1, -1):
            if suff[i] != cur:
                cand.add(i + 1)
                cand.add(i)
                cur = suff[i]

        def score(arr):
            m = len(arr)
            if m < 2:
                return 0
            p_arr = [0] * m
            s_arr = [0] * m
            p = 0
            for i in range(m):
                p = gcd(p, arr[i])
                p_arr[i] = p
            s = 0
            for i in range(m - 1, -1, -1):
                s = gcd(s, arr[i])
                s_arr[i] = s
            cnt = 0
            for i in range(m - 1):
                if p_arr[i] == s_arr[i + 1]:
                    cnt += 1
            return cnt

        for i in cand:
            ans = max(ans, score(nums[:i] + nums[i + 1 :]))

        return ans