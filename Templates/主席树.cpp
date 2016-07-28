struct fotiletree{
    struct node{
        int sum,lson,rson;
    }t[300000*15+1];
    int ver,cur;
    int n;
    fotiletree(){
        ver=cur=0;
    }
    int p,v;
    void update(int& o,int l,int r){
        t[++cur]=t[o];
        o=cur;
        t[o].sum+=v;
        if (l==r)
            return;
        int mid=(l+r)/2;
        if (p<=mid)
            update(t[o].lson,l,mid);
        else update(t[o].rson,mid+1,r);
    }
    int root[300001];
    void ins(int x){
        ver++;
        p=x,v=1;
        root[ver]=root[ver-1];
        update(root[ver],1,n);
    }
    int query(int lnow,int rnow,int l,int r,int k){
        if (l==r)
            return l;
        int sum=t[t[rnow].lson].sum-t[t[lnow].lson].sum;
        int mid=(l+r)/2;
        if (sum>=k)
            return query(t[lnow].lson,t[rnow].lson,l,mid,k);
        else return query(t[lnow].rson,t[rnow].rson,mid+1,r,k-sum);
    }
    int kth(int l,int r,int k){
        return query(root[l-1],root[r],1,n,k);
    }
};
