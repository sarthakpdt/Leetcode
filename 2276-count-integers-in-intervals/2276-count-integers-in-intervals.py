class CountIntervals(object):
    def __init__(self):
        self.intervals=[]
        self.total=0

    def add(self,left,right):
        import bisect
        i=bisect.bisect_left(self.intervals,[left,-1])
        
        if i>0 and self.intervals[i-1][1]>=left-1:
            i-=1
        
        while i<len(self.intervals) and self.intervals[i][0]<=right+1:
            l,r=self.intervals[i]
            if r<left:
                i+=1
                continue
            left=min(left,l)
            right=max(right,r)
            self.total-=r-l+1
            self.intervals.pop(i)
        
        self.intervals.insert(i,[left,right])
        self.total+=right-left+1

    def count(self):
        return self.total