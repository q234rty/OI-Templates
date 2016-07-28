typedef long long ll;
int mod;
struct matrix{
    int r,c;
    ll a[51][51];
    matrix(int r,int c){
        this->r=r;
        this->c=c;
        memset(a,0,sizeof(a));
    }
    ll * operator[](int p){
        return a[p];
    }
    matrix operator =(const matrix& rhs){
        //puts("WTF");
        assert(r==rhs.r && c==rhs.c);
        memcpy(a,rhs.a,sizeof(a));
        return *this;
    }
    matrix operator *(matrix& rhs){
        assert(c==rhs.r);
        //puts("WTF");
        matrix res(r,rhs.c);
        //puts("WTF");
        for(int i=1;i<=r;i++)
            for(int j=1;j<=rhs.c;j++)
                for(int k=1;k<=c;k++)
                    (res[i][j]+=((a[i][k]*rhs[k][j])%mod))%=mod;
        //puts("WTF");
        return res;
    }
    matrix operator *=(matrix& rhs){
        return *this=(*this)*rhs;
    }
};
matrix power(const matrix& mat,ll b){
    //puts("WTF");
    matrix ret(mat.r,mat.c);
    matrix t(mat.r,mat.c);
    t=mat;
    //puts("line 48");
    for(int i=1;i<=mat.r;i++)
        ret[i][i]=1;
    while(b){
        //puts("WTF");
        if (b%2)
            ret=ret*t;
        t=t*t;
        b/=2;
    }
    return ret;
}
