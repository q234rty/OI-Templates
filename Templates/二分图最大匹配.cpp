struct edge{
    int from,to,next;
};
struct graph{
    int nl,m;
    edge e[maxm];
    int first[maxn];
    int match[maxn];
    bool vis[maxn];
    void init(int nl){
        this->nl=nl;
        m=0;
        memset(first,-1,sizeof(first));
    }
    void addedge(int from,int to){
        e[++m]=(edge){from,to,first[from]};
        first[from]=m;
    }
    bool dfs(int u){
        for(int i=first[u];i!=-1;i=e[i].next){
            int v=e[i].to;
            if (!vis[v]){
                vis[v]=true;
                if (match[v]==-1 || dfs(match[v])){
                    match[u]=v;
                    match[v]=u;
                    return true;
                }
            }
        }
        return false;
    }
    int work(){
        int ans=0;
        memset(match,-1,sizeof(match));
        for(int i=1;i<=nl;i++)
            if (match[i]==-1){
                memset(vis,0,sizeof(vis));
                if (dfs(i))
                    ++ans;
            }
        return ans;
    }
};
