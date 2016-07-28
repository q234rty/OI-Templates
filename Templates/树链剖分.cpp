struct edge{
    int to,next;
};
struct graph{
    int n,m;
    edge e[maxm];
    int first[maxn];
    int dep[maxn],fa[maxn],id[maxn],top[maxn],sz[maxn],son[maxn];
    int cur;
    segtree t;
    void init(int n){
        this->n=t.n=n;
        m=0;
        memset(first,-1,sizeof(first));
    }
    void addedge(int from,int to){
        e[++m]=(edge){to,first[from]};
        first[from]=m;
    }
    void dfs(int u){
        sz[u]=1;
        for(int i=first[u];i!=-1;i=e[i].next){
            int v=e[i].to;
            if (dep[v])
                continue;
            fa[v]=u;
            dep[v]=dep[u]+1;
            dfs(v);
            sz[u]+=sz[v];
            if (!son[u] || sz[v]>sz[son[u]])
                son[u]=v;
        }
    }
    void dfs2(int u,int tp){
        top[u]=tp;
        id[u]=++cur;
        if (son[u])
            dfs2(son[u],tp);
        for(int i=first[u];i!=-1;i=e[i].next){
            int v=e[i].to;
            if (!id[v])
                dfs2(v,v);
        }
    }
    void prepare(){
        for(int i=1;i<=n;i++){
            if (dep[i])
                continue;
            dep[i]=1;
            fa[i]=-1;
            dfs(i);
        }
        for(int i=1;i<=n;i++)
            if (!id[i])
                dfs2(i,i);
    }
    void update(int u,int x){
        t.update(id[u],x);
    }
    int query(int u,int v,int op){
        int ret=op==1?0:-INF;
        for(;top[u]!=top[v];u=fa[top[u]]){
            if (dep[top[u]]<dep[top[v]])
                swap(u,v);
            if (op==1)
                ret+=t.query(id[top[u]],id[u],op);
            else ret=max(ret,t.query(id[top[u]],id[u],op));
        }
        if (dep[u]>dep[v])
            swap(u,v);
        if (op==1)
            ret+=t.query(id[u],id[v],op);
        else ret=max(ret,t.query(id[u],id[v],op));
        return ret;
    }
};
