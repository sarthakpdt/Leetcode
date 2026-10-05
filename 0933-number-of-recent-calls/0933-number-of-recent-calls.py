class RecentCounter(object):

    def __init__(self):
        self.q=[]

    def ping(self, t):
        """
        :type t: int
        :rtype: int
        """
        self.q.append(t)

        while self.q[0]<t-3000:
            self.q.pop(0)

        return len(self.q)