class Solution(object):
    def areNumbersAscending(self,s):
        a=s.split()
        prev=0

        for x in a:
            if x.isdigit():
                x=int(x)

                if x<=prev:
                    return False

                prev=x

        return True