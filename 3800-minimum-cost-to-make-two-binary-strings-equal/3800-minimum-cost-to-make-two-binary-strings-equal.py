class Solution(object):
    def minimumCost(self, s, t, flipCost, swapCost, crossCost):
        """
        :type s: str
        :type t: str
        :type flipCost: int
        :type swapCost: int
        :type crossCost: int
        :rtype: int
        """
        n = len(s)
        cntA = cntB = 0
        for i in range(n):
            if s[i] != t[i]:
                if s[i] == '0' and t[i] == '1':
                    cntA += 1
                else:  # s[i] == '1' and t[i] == '0'
                    cntB += 1

        # already equal
        if cntA == 0 and cntB == 0:
            return 0

        res = 0

        # Resolve opposite-type pairs (each resolves two mismatches)
        pairs_opposite = min(cntA, cntB)
        res += pairs_opposite * min(swapCost, 2 * flipCost)
        cntA -= pairs_opposite
        cntB -= pairs_opposite

        # Remaining are same-type mismatches
        rem = cntA + cntB  # all of the same type now
        pairs_same = rem // 2
        res += pairs_same * min(2 * flipCost, crossCost + swapCost)

        # If one remains, fix by a single flip
        if rem % 2 == 1:
            res += flipCost

        return res