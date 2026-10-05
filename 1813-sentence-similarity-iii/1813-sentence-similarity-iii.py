class Solution(object):
    def areSentencesSimilar(self, sentence1, sentence2):
        w1=sentence1.split(" ")
        w2=sentence2.split(" ")
        n1=len(w1)
        n2=len(w2)
        if n1>n2:
            w1,w2=w2,w1
            n1,n2=n2,n1
        i=0
        while i<n1 and w1[i]==w2[i]:
            i+=1
        j=0
        while j<n1 and w1[n1-1-j]==w2[n2-1-j]:
            j+=1
        return i+j>=n1