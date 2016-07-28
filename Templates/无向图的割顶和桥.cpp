struct edge{
    int from,to,next;
};
struct graph{
    int n,m;
    edge e[400001];
    bool iscut[100001];
    bool isbri[400001];
    int low[100001];
    int pre[100001];
    int first[100001];
    int cnt;
    graph(){
        m=0;
        cnt=0;
        memset(first,-1,sizeof(first));
        memset(pre,0,sizeof(pre));
        memset(iscut,0,sizeof(iscut));
        memset(isbri,0,sizeof(isbri));
    }
    void addedge(int from,int to){
        e[++m]=(edge){from,to,first[from]};
        first[from]=m;
    }
    int dfs(int u,int fa){
        int& lowu=low[u];
        lowu=pre[u]=++cnt;
        int child=0;
        for(int i=first[u];i!=-1;i=e[i].next){
            int v=e[i].to;
            if (!pre[v]){
                child++;
                int lowv=dfs(v,u);
                lowu=min(lowu,lowv);
                if (lowv>=pre[u])
                    iscut[u]=true;
                if (lowv>pre[u])
                    isbri[i]=true;   //Only one of (u,v) and (v,u) will be labeled,be careful!
            }
            else if (pre[v]<pre[u] && v!=fa)
                lowu=min(lowu,pre[v]);
        }
        if (fa<0 && child==1)
            iscut[u]=false;
        return lowu;
    }
};
