class Solution(object):
    def checkOverlap(self, radius, xCenter, yCenter, x1, y1, x2, y2):
        """
        :type radius: int
        :type xCenter: int
        :type yCenter: int
        :type x1: int
        :type y1: int
        :type x2: int
        :type y2: int
        :rtype: bool
        """
        if xCenter<x1:
            x=x1
        elif xCenter>x2:
            x=x2
        else:
            x=xCenter

        if yCenter<y1:
            y=y1
        elif yCenter>y2:
            y=y2
        else:
            y=yCenter

        dx=x-xCenter
        dy=y-yCenter

        if dx*dx+dy*dy<=radius*radius:
            return True
        else:
            return False
        