from collections import Counter
class Encrypter(object):
    def __init__(self, keys, values, dictionary):
        self.mp={k:v for k,v in zip(keys,values)}
        self.cnt=Counter()
        for w in dictionary:
            e=self.encrypt(w)
            if e:
                self.cnt[e]+=1
    def encrypt(self, word1):
        res=[]
        for c in word1:
            if c not in self.mp:
                return ""
            res.append(self.mp[c])
        return "".join(res)
    def decrypt(self, word2):
        return self.cnt[word2]