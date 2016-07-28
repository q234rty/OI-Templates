struct trie{
    static const int sigma=26;
    static const int maxsize=3000001;
    int ch[maxsize][sigma];
    int sz;
    int num[maxsize];
    int res[maxsize];
    int n;
    int cnt;
    inline int idx(char c){
        return c-'a';
    }
    trie(){
        sz=1;
        memset(ch,0,sizeof(ch));
        n=0;
    }
    int ins(char* s){
        int u=0,len=strlen(s);
        //printf("inserting:%s\n",s.c_str());
        for(int i=0;i<len;i++){
            int c=idx(s[i]);
            if (!ch[u][c]){
                memset(ch[sz],0,sizeof(ch[sz]));
                num[sz]=0;
                //printf("u=%d,sz=%d\n",u,sz);
                //assert(u!=sz);
                ch[u][c]=sz++;
            }
            u=ch[u][c];
        }
        if (num[u])
            return num[u];
        else return num[u]=++n;
    }
};
