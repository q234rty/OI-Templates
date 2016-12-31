typedef long long ll;
struct edge{
    int to,cap,next;
};
struct graph{
    int n,m;
    edge e[maxm];
    int first[maxn],cur[maxn];
    void init(int n){
        this->n=n;
        memset(first,-1,sizeof(first));
        m=1;
    }
    void addedge(int from,int to,int cap){
        e[++m]=(edge){to,cap,first[from]};
        first[from]=m;
        e[++m]=(edge){from,0,first[to]};
        first[to]=m;
    }
    int q[maxn];
    int dist[maxn];
    int t;
    bool bfs(int s){
        int l=1,r=1;
        q[1]=s;
        memset(dist,-1,sizeof(dist));
        dist[s]=0;
        while(l<=r){
            int u=q[l++];
            for(int i=first[u];i!=-1;i=e[i].next){
                int v=e[i].to;
                if ((dist[v]!=-1) || (!e[i].cap))
                    continue;
                dist[v]=dist[u]+1;
                q[++r]=v;
            }
        }
        return dist[t]!=-1;
    }
    int dfs(int u,int flow){
        if (u==t)
            return flow;
        for(int& i=cur[u];i!=-1;i=e[i].next){
            int v=e[i].to;
            if (!e[i].cap || dist[v]!=dist[u]+1)
                continue;
            int t=dfs(v,min(flow,e[i].cap));
            if (t){
                e[i].cap-=t;
                e[i^1].cap+=t;
                return t;
            }
        }
        return 0;
    }
    ll dinic(int s,int t){
        ll ans=0;
        this->t=t;
        while(bfs(s)){
            int flow;
            memcpy(cur,first,sizeof(cur));
            while(flow=dfs(s,INF))
                ans+=(ll)flow;
        }
        return ans;
    }
};
