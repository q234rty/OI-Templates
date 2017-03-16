const int maxn=100001;
struct sam{
    static const int maxt=maxn*2;
    int ch[maxt][26];
    int f[maxt];
    int st[maxt];
    int to[maxt];
    bool vis[maxt];
    int cur,p;
    sam(){
        p=cur=1;
    }
    void extend(int c,int pos){
        int np=++cur;
        st[np]=st[p]+1;
        to[np]=pos;
        for(;p&&!ch[p][c];p=f[p])
            ch[p][c]=np;
        //printf("first time to %d,st[np]=%d\n",p,st[np]);
        if (!p)
            f[np]=1;
        else{
            int pot=ch[p][c];
            if (st[pot]==st[p]+1)
                f[np]=pot;
            else{
                int wish=++cur;
                st[wish]=st[p]+1;
                for(;p&&ch[p][c]==pot;p=f[p])
                    ch[p][c]=wish;
                for(int i=0;i<26;i++)
                    ch[wish][i]=ch[pot][i];
                f[wish]=f[pot];
                f[pot]=f[np]=wish;
            }
        }
        //printf("%d %d,%d %d\n",np,f[np],st[np],st[f[np]]);
        p=np;
    }
    int now;
    int ct[maxt][26];
    int sa[maxn],rnk[maxn],height[maxn];
    void dfs(int u){
        if (to[u])
            sa[++now]=to[u];
        //printf("%d %d\n",u,to[u]);
        for(int i=0;i<26;i++)
            if (ct[u][i])
                dfs(ct[u][i]);
    }
    void getsa(char* s){
        int n=strlen(s+1);
        for(int i=n;i;i--)
            extend(s[i]-'a',i);
        vis[1]=true;
        for(int i=1;i<=cur;i++)
            if (to[i])
                for(int pos=n,j=i;!vis[j];vis[j]=true,j=f[j],pos--){
                    pos-=st[j]-st[f[j]]-1;
                    ct[f[j]][s[pos]-'a']=j;
                }
        dfs(1);
        for(int i=1;i<=n;i++)
            rnk[sa[i]]=i;
        int k=0;
        for(int i=1;i<=n;i++){
            if (k)
                k--;
            int j=sa[rnk[i]-1];
            while(s[i+k]==s[j+k])
                k++;
            height[rnk[i]]=k;
        }
    }
};
