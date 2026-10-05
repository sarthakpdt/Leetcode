class Solution(object):
    def getFolderNames(self, names):
        seen={}
        res=[]
        for name in names:
            if name not in seen:
                seen[name]=1
                res.append(name)
            else:
                k=seen[name]
                new_name=name+"("+str(k)+")"
                while new_name in seen:
                    k+=1
                    new_name=name+"("+str(k)+")"
                seen[name]=k+1
                seen[new_name]=1
                res.append(new_name)
        return res