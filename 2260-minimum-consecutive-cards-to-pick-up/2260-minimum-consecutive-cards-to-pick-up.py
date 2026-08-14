class Solution(object):
    def minimumCardPickup(self, cards):
        """
        :type cards: List[int]
        :rtype: int
        """
        left=0
        minn=float('inf')
        freq={}
        for right in range(len(cards)):
            freq[cards[right]]=freq.get(cards[right],0)+1
            while freq[cards[right]]>1:
                minn=min(minn,right-left+1)
                freq[cards[left]]-=1
                left+=1
        if minn==float('inf'):
            return -1
        return minn