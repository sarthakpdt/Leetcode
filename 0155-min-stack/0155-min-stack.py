class MinStack(object):
    def __init__(self):
        self.stack=[]
        self.minstack=[]

    def push(self,value):
        self.stack.append(value)
        if not self.minstack or value<=self.minstack[-1]:
            self.minstack.append(value)

    def pop(self):
        if self.stack:
            value=self.stack.pop()
            if value==self.minstack[-1]:
                self.minstack.pop()

    def top(self):
        if self.stack:
            return self.stack[-1]
        return -1

    def getMin(self):
        if self.minstack:
            return self.minstack[-1]
        return -1