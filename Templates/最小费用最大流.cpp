struct edge{
    int from,to,next,cap,cost;
};
const int maxn=401;
const int maxm=30007;
struct graph{
    int n,m;
    int first[maxn];
    edge e[maxm];
    int p[maxn],d[maxn];
    bool inq[maxn];
    int cnt[maxn];
    void init(int n){
        this->n=n;
        m=1;
    }
    void addedge(int from,int to,int cap,int cost){
        e[++m]=(edge){from,to,first[from],cap,cost};
        first[from]=m;
        e[++m]=(edge){to,from,first[to],0,-cost};
        first[to]=m;
    }
    int q[maxn];
    int t;
    bool spfa(int s){
        int l=0,r=0;
        for(int i=1;i<=n;i++)
            d[i]=INF;
        d[s]=0;
        q[(r++)%n]=s;
        memset(inq,0,n+1);
        inq[s]=true;
        while(l<r){
            int u=q[(l++)%n];
            inq[u]=0;
            for(int i=first[u];i;i=e[i].next){
                if (!e[i].cap)
                    continue;
                int v=e[i].to;
                if (d[u]!=INF && d[v]>d[u]+e[i].cost){
                    d[v]=d[u]+e[i].cost;
                    p[v]=i;
                    if (!inq[v])
                        q[(r++)%n]=v,inq[v]=true;
                }
            }
        }
        return d[t]!=INF;
    }
    pair<int,int> mcmf(int s,int t){
        this->t=t;
        int flow=0,cost=0;
        while(spfa(s)){
            int delta=INF;
            for(int i=t;i!=s;i=e[p[i]].from)
                if (e[p[i]].cap<delta)
                    delta=e[p[i]].cap;
            for(int i=t;i!=s;i=e[p[i]].from)
                e[p[i]].cap-=delta,e[p[i]^1].cap+=delta;
            flow+=delta;
            cost+=delta*d[t];
        }
        return make_pair(flow,cost);
    }
}g;
