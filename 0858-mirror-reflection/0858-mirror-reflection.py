class Solution(object):
    def mirrorReflection(self,p,q):
        x=p
        while x%q!=0:
            x+=p
        a=x//q
        b=x//p
        if a%2==0:
            return 2
        elif b%2==1:
            return 1
        else:
            return 0