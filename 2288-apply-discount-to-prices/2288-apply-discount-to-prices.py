class Solution(object):
    def discountPrices(self, sentence, discount):
        res=[]
        for w in sentence.split(" "):
            if w.startswith("$") and w[1:].isdigit():
                val=int(w[1:])*(1-discount/100.0)
                res.append("${:.2f}".format(val))
            else:
                res.append(w)
        return " ".join(res)