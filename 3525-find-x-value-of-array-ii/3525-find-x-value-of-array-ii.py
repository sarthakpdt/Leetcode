class Solution(object):
    def resultArray(self,nums,k,queries):
        n=len(nums)
        size=4*n
        prod=[1]*size
        cnt=[[0]*k for i in range(size)]
        def merge(p1,c1,p2,c2):
            p=(p1*p2)%k
            c=c1[:]
            for i in range(k):
                c[(p1*i)%k]+=c2[i]
            return p,c
        def build(i,l,r):
            if l==r:
                prod[i]=nums[l]%k
                cnt[i][prod[i]]=1
                return
            mid=(l+r)//2
            build(i*2,l,mid)
            build(i*2+1,mid+1,r)
            prod[i],cnt[i]=merge(
                prod[i*2],cnt[i*2],
                prod[i*2+1],cnt[i*2+1]
            )
        def update(i,l,r,pos,val):
            if l==r:
                prod[i]=val%k
                cnt[i]=[0]*k
                cnt[i][prod[i]]=1
                return
            mid=(l+r)//2
            if pos<=mid:
                update(i*2,l,mid,pos,val)
            else:
                update(i*2+1,mid+1,r,pos,val)
            prod[i],cnt[i]=merge(
                prod[i*2],cnt[i*2],
                prod[i*2+1],cnt[i*2+1]
            )
        def query(i,l,r,ql):
            if l>=ql:
                return prod[i],cnt[i]
            mid=(l+r)//2
            if ql>mid:
                return query(i*2+1,mid+1,r,ql)
            p1,c1=query(i*2,l,mid,ql)
            p2,c2=query(i*2+1,mid+1,r,ql)
            return merge(p1,c1,p2,c2)
        build(1,0,n-1)
        ans=[]
        for i in range(len(queries)):
            index,value,start,x=queries[i]
            update(1,0,n-1,index,value)
            p,c=query(1,0,n-1,start)
            ans.append(c[x])
        return ans