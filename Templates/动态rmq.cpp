struct segtree{
    ll minv[maxn*8];
    int n,p;
    ll v;
    segtree(){
        memset(minv,0,sizeof(minv));
    }
    void _update_(int o,int l,int r){
        if (l==r){
            minv[o]=v;
            assert(l==p);
            return;
        }
        ll m=l+(r-l)/2;
        //puts("line 35");
        if (p<=m)
            _update_(o*2,l,m);
        else _update_(o*2+1,m+1,r);
        minv[o]=min(minv[o*2],minv[o*2+1]);
    }
    void update(int p,ll v){
        this->p=p;
        this->v=v;
        _update_(1,1,n);
        //puts("updated once");
    }
    int ql,qr;
    ll _query_(int o,int l,int r){
        if (ql<=l && r<=qr)
            return minv[o];
        ll ans=INF;
        int m=l+(r-l)/2;
        if (ql<=m)
            ans=min(ans,_query_(o*2,l,m));
        if (qr>=m+1)
            ans=min(ans,_query_(o*2+1,m+1,r));
        return ans;
    }
    ll query(int l,int r){
        if (l>r)
            return INF;
        ql=l;
        qr=r;
        return _query_(1,1,n);
    }
};
