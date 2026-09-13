class Solution(object):
    def pathInZigZagTree(self, label):
        """
        :type label: int
        :rtype: List[int]
        """
        ans=[]
        while label>=1:
            ans.append(label)
            row=label.bit_length()
            st=1<<(row-1)
            end=(1<<row)-1
            label=(st+end-label)//2
        ans.reverse()
        return ans
        