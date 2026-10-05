class Solution(object):
    def oddCells(self, m, n, indices):
        rows=[0]*m
        cols=[0]*n
        for r,c in indices:
            rows[r]^=1
            cols[c]^=1
        odd_r=sum(rows)
        odd_c=sum(cols)
        return odd_r*(n-odd_c)+odd_c*(m-odd_r)