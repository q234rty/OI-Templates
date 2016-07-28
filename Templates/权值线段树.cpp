struct segkth{
    int sumv[800001];
    int p,v,n;
    void clr(){
        memset(this,0,sizeof(*this));
    }
    segkth(){
        clr();
    }
    void update__(int o,int l,int r){
        if (l==r){
            assert(l==p);
            sumv[o]+=v;
            return;
        }
        int m=l+(r-l)/2;
        if (p<=m)
            update__(o*2,l,m);
        else update__(o*2+1,m+1,r);
    }
    void update(int p,int v){
        this->p=p;
        this->v=v;
        update__(1,1,n);
    }
    int kth__(int o,int l,int r,int k){
        if (l==r)
            return l;
        int m=l+(r-l)/2;
        if (k<=sumv[o*2])
            return kth__(o*2,l,m,k);
        else return kth__(o*2+1,m+1,r,k-sumv[o*2]);
    }
    int kth(int k){
        return kth__(1,1,n,k);
    }
    int ql,qr;
    int rank__(int o,int l,int r){
        int m=l+(r-l)/2;
        if (l>=ql && r<=qr)
            return sumv[o];
        int ret=0;
        if (ql<=m)
            ret+=rank__(o*2,l,m);
        if (qr>m)
            ret+=rank__(o*2+1,m+1,r);
        return ret;
    }
    int rank(int x){
        if (x==1)
            return 1;
        this->ql=1;
        this->qr=x-1;
        return rank__(1,1,n)+1;
    }
};
