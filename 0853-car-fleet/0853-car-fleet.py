class Solution(object):
    def carFleet(self, target, position, speed):
        cars=sorted(zip(position, speed), reverse=True)
        ans=0
        cur=0.0
        for i in range(len(cars)):
            t=float(target-cars[i][0])/cars[i][1]
            if t>cur:
                ans+=1
                cur=t
        return ans