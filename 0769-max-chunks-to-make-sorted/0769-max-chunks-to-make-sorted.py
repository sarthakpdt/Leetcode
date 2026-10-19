class Solution(object):
    def maxChunksToSorted(self, arr):
        ans=0
        mx=0
        for i in range(len(arr)):
            mx=max(mx, arr[i])
            if mx==i:
                ans+=1
        return ans