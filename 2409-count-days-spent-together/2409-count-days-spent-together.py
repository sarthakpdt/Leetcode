class Solution(object):
    def countDaysTogether(self, arriveAlice, leaveAlice, arriveBob, leaveBob):
        """
        :type arriveAlice: str
        :type leaveAlice: str
        :type arriveBob: str
        :type leaveBob: str
        :rtype: int
        """
        days=[31,28,31,30,31,30,31,31,30,31,30,31]
        def convert(date):
            m,d=map(int,date.split('-'))
            total=d
            for i in range(m-1):
                total+=days[i]
            return total
        a=convert(arriveAlice)
        b=convert(leaveAlice)
        c=convert(arriveBob)
        d=convert(leaveBob)
        start=max(a,c)
        end=min(b,d)
        return max(0,end-start+1)