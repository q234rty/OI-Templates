typedef long long ll;
struct edge{
    int from,to;
    int dist;
    int next;
};
struct graph{
    int n,m;
    ll d[1002];
    edge e[200001];
    int first[1002];
    bool inq[1002];
    int cnt[1002];
    int q[2000002];
    void init(int n){
        this->n=n;
        memset(first,-1,sizeof(int)*1002);
        m=0;
    }
    void addedge(int from,int to,int dist){
        e[++m]=(edge){from,to,dist,first[from]};
        first[from]=m;
    }
    bool spfa(int s){
        //int q[100004];
        int f=1,r=1;
        memset(d,0x3f,sizeof(ll)*1002);
        memset(inq,0,sizeof(int)*1002);
        memset(cnt,0,sizeof(int)*1002);
        d[s]=0;
        q[r]=s;
        r++;
        inq[s]=true;
        cnt[s]=1;
        while (f<r){
            register int u=q[f];
            f++;
            inq[u]=false;
            register int i=first[u];
            while(i!=-1){
                register ll t=d[u]+e[i].dist;
                register int v=e[i].to;
                if(d[u]<INF && d[v]>t){
                    d[v]=t;
                    if (!inq[v]){
                        q[r]=v;
                        r++;
                        inq[v]=true;
                        if (++cnt[v]>n){
                            return false;
                        }
                    }
                }
                i=e[i].next;
            }
        }
        return true;
    }
};
