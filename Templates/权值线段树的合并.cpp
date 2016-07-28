struct segmerge{
    static const int maxt=18*100000+1;
    static const int maxn=100001;
    struct node{
        int sum,lson,rson;
        node(){
            sum=lson=rson=0;
        }
    };
    node t[maxt];
    int root[maxn];
    int fa[maxn];
    int n,cur;
    void init(int n){
        this->n=n;
        cur=0;
        for(int i=1;i<=n;i++)
            root[i]=++cur,fa[i]=i;
    }
    int getf(int x){
        return fa[x]==x?x:fa[x]=getf(fa[x]);
    }
    int p,v;
    void update__(int o,int l,int r){
        t[o].sum+=v;
        //printf("o=%d,l=%d,r=%d\n",o,l,r);
        if (l==r)
            return;
        int m=(l+r)/2;
        if (p<=m){
            if (!t[o].lson)
                t[o].lson=++cur;
            update__(t[o].lson,l,m);
        }
        else {
            if (!t[o].rson)
                t[o].rson=++cur;
            update__(t[o].rson,m+1,r);
        }
    }
    int kth__(int o,int l,int r,int k){
        int m=(l+r)/2,ret=0;
        if (l==r)
            return k==1?l:-1;
        if (k<=t[t[o].lson].sum)
            return kth__(t[o].lson,l,m,k);
        else
            return t[o].rson?kth__(t[o].rson,m+1,r,k-t[t[o].lson].sum):-1;
    }
    int merge__(int x,int y){
        if (!x)
            return y;
        if (!y)
            return x;
        t[x].lson=merge__(t[x].lson,t[y].lson);
        t[x].rson=merge__(t[x].rson,t[y].rson);
        t[x].sum+=t[y].sum;
        return x;
    }
    void ins(int x,int c){
        p=x,v=1;
        update__(root[getf(c)],1,n);
    }
    int kth(int k,int c){
        return kth__(root[getf(c)],1,n,k);
    }
    void mer(int x,int y){
        int u=getf(x),v=getf(y);
        if (u==v)
            return;
        fa[u]=v;
        root[v]=merge__(root[u],root[v]);
    }
}t;
