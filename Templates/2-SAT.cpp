struct edge{
    int from,to,next;
};
struct twosat{
    int n,m;
    edge e[2001];
    bool mark[201];
    int first[201];
    int s[201],c;
    inline int other(int x){
        return x%2?x+1:x-1;
    }
    twosat(){
        m=0;
        memset(mark,0,sizeof(mark));
        memset(first,-1,sizeof(first));
    }
    void clear(){
        m=0;
        memset(mark,0,sizeof(mark));
        memset(first,-1,sizeof(first));
    }
    void addedge(int from,int to){
        e[++m]=(edge){from,to,first[from]};
        first[from]=m;
    }
    void addclue(int x,int xval,int y,int yval){
        x=x*2+xval-1;
        y=y*2+yval-1;
        addedge(other(x),y);
        addedge(other(y),x);
    }
    bool dfs(int x){
        if (mark[x])
            return true;
        if (mark[other(x)])
            return false;
        mark[x]=true;
        s[++c]=x;
        for(int i=first[x];i!=-1;i=e[i].next){
            if (!dfs(e[i].to))
                return false;
        }
        return true;
    }
    bool solve(){
        /*for(int i=1;i<=2*n;i++){
            printf("edges from %d:",i);
            for(int j=first[i];j!=-1;j=e[j].next)
                printf("%d ",e[j].to);
            putchar('\n');
        }*/
        for(int i=1;i<=2*n;i+=2){
            if (!mark[i] && !mark[i+1]){
                c=0;
                if (!dfs(i)){
                    for(int j=1;j<=c;j++)
                        mark[s[j]]=false;
                    c=0;
                    if (!dfs(i+1))
                        return false;
                }
            }
        }
        return true;
    }
};
