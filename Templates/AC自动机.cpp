struct acatm{
    int ch[201][26];
    int val[201];
    int f[201];
    int last[201];
    bool match[1000001][21];
    int sz,cnt;
    acatm(){
        sz=1;
        cnt=0;
        memset(ch[0],0,sizeof(ch[0]));
        memset(val,0,sizeof(val));
    }
    inline int idx(char c){
        return c-'a';
    }
    void ins(char* s){
        int len=strlen(s),u=0;
        for(int i=0;i<len;i++){
            int c=idx(s[i]);
            int v=ch[u][c];
            if (!v){
                ch[u][c]=v=sz++;
                memset(ch[v],0,sizeof(ch[v]));
                val[v]=0;
            }
            u=v;
        }
        val[u]=++cnt;
    }
    void getfail(){
        queue<int> q;
        f[0]=0;
        last[0]=0;
        for(int i=0;i<26;i++){
            int u=ch[0][i];
            if (u){
                q.push(u);
                f[u]=0;
                last[u]=0;
            }
        }
        while(!q.empty()){
            int r=q.front();q.pop();
            for(int i=0;i<26;i++){
                int u=ch[r][i];
                if (!u){
                    ch[r][i]=ch[f[r]][i];
                    continue;
                }
                int v=f[r];
                while(v && !ch[v][i])
                    v=f[v];
                f[u]=ch[v][i];
                //printf("f[%d]=%d\n",u,f[u]);
                last[u]=val[f[u]]?f[u]:last[f[u]];
                q.push(u);
            }
        }
    }
    void print(int i,int u){
        if (u){
            match[i][val[u]]=true;
            print(i,last[u]);
        }
    }
    void fi(char* s){
        memset(match,0,sizeof(match));
        int len=strlen(s),u=0;
        for(int i=0;i<len;i++){
            int c=idx(s[i]);
            u=ch[u][c];
            //printf("i=%d,u=%d\n",i,u);
            if (val[u])
                print(i,u);
            else if (last[u]) print(i,last[u]);
        }
    }
};
