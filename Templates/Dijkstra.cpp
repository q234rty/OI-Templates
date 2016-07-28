typedef long long ll;
struct edge{
    ll from,to,dist,next;
};
struct heapnode{
    ll d,u;
    bool operator < (const heapnode& rhs) const{
        return d>rhs.d;
    }
};
struct graph{
    ll n,m;
    edge* e=new edge[200003];
    ll* first=new ll[200003];
    ll* d=new ll[200003];
    ll* p=new ll[200003];
    bool* done=new bool[200003];
    void init(ll n){
        this->n=n;
        m=0;
        memset(first,-1,200003*sizeof(ll));
    }
    void addedge(ll from,ll to,ll dist){
        e[++m]=(edge){from,to,dist,first[from]};
        first[from]=m;
    }
    void dijkstra(ll s){
        priority_queue<heapnode> q;
        memset(d,0x3f,200003*sizeof(ll));
        d[s]=0;
        memset(done,0,200003*sizeof(bool));
        memset(p,0,200003*sizeof(ll));
        q.push((heapnode){0,s});
        while(!q.empty()){
            ll u=q.top().u;
            q.pop();
            if (done[u])
                continue;
            done[u]=true;
            //prllf("u=%d\n",u);
            ll i=first[u];
            while (i!=-1){
                if (d[u]+e[i].dist<d[e[i].to]){
                    d[e[i].to]=d[u]+e[i].dist;
                    p[e[i].to]=u;
                    q.push((heapnode){d[e[i].to],e[i].to});
                }
                i=e[i].next;
            }
        }
    }
};
