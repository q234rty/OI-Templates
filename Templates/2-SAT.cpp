struct twosat{
    struct edge{
        int to,next;
    }e[maxm];
    inline void update(int& x,int y){
        if (x>y)
            x=y;
    }
    int n,m;
    int first[maxn];
    void init(int n){
        n=n*2+1;
        this->n=n;
        memset(first,0,(n+1)*4);
        m=0;
    }
    void addedge(int from,int to){
        //printf("%d %d\n",from,to);
        e[++m]=(edge){to,first[from]};
        first[from]=m;
    }
    int low[maxn],pre[maxn],sccno[maxn],cl,tp,now;
    int stk[maxn];
    void dfs(int u){
        pre[u]=low[u]=++cl;
        stk[++tp]=u;
        for(int i=first[u];i;i=e[i].next){
            int v=e[i].to;
            if (!pre[v]){
                dfs(v);
                update(low[u],low[v]);
            }else if (!sccno[v])
                update(low[u],pre[v]);
        }
        if (low[u]==pre[u]){
            now++;
            while(tp){
                int v=stk[tp--];
                sccno[v]=now;
                if (v==u)
                    break;
            }
        }
    }
    void addclue(int x,int xval,int y,int yval){
        x=x*2+xval,y=y*2+yval;
        addedge(x^1,y);
        addedge(y^1,x);
    }
    void set(int x,int val){
        x=x*2+val;
        addedge(x^1,x);
    }
    int ans[maxn];
    bool work(){
        memset(pre,0,(n+1)*4);
        memset(sccno,0,(n+1)*4);
        memset(low,0,(n+1)*4);
        tp=cl=now=0;
        for(int i=1;i<=n;i++)
            if (!pre[i])
                dfs(i);
        for(int i=1;i<=n/2;i++){
            int x=i*2,y=i*2+1;
            if (sccno[x]==sccno[y])
                return false;
            ans[i]=(sccno[x]>sccno[y]);
        }
        return true;
    }
};