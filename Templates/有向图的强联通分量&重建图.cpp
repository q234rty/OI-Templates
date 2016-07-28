struct edge{
    int from,to,next;
};
struct graph{
    int n,m;
    edge e[100001];
    int first[10001];
    int lowlink[10001];
    int sccno[10001];
    int pre[10001];
    int num[10001];
    int out0[10001];
    int cnt,dfsc;
    stack<int> s;
    graph(){
        m=0;
        memset(first,-1,sizeof(first));
    }
    void addedge(int from,int to){
        e[++m]=(edge){from,to,first[from]};
        first[from]=m;
    }
    void dfs(int u){
        pre[u]=lowlink[u]=++dfsc;
        s.push(u);
        for(int i=first[u];i!=-1;i=e[i].next){
            int v=e[i].to;
            if (!pre[v]){
                dfs(v);
                lowlink[u]=min(lowlink[u],lowlink[v]);
            } else if (!sccno[v]){
                lowlink[u]=min(lowlink[u],pre[v]);
            }
        }
        if (lowlink[u]==pre[u]){
            cnt++;
            for(;;){
                int x=s.top();
                s.pop();
                sccno[x]=cnt;
                num[cnt]++;
                if (x==u)
                    break;
            }
        }
    }
    void getscc(){
        dfsc=cnt=0;
        memset(pre,0,sizeof(pre));
        memset(sccno,0,sizeof(sccno));
        memset(num,0,sizeof(num));
        for(int i=1;i<=n;i++)
            if (!pre[i])
                dfs(i);
    }
    void rebuild(){
        memset(out0,1,sizeof(out0));
        for(int i=1;i<=n;i++){
            for(int j=first[i];j!=-1;j=e[j].next)
                if (sccno[i]!=sccno[e[j].to])
                    out0[sccno[i]]=false;
        }
    }
};
