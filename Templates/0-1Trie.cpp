struct trie{
    int ch[3200001][2];
    int val[3200001];
    int sz;
    void init(){
        sz=0;
        memset(ch[0],0,sizeof(ch[0]));
        val[0]=0;
    }
    void ins(int x){
        int now=0;
        for(int i=30;i>=0;i--){
            int id=(x&(1<<i))?1:0;
            if (!ch[now][id]){
                ch[now][id]=++sz;
                memset(ch[sz],0,sizeof(ch[sz]));
                val[sz]=0;
            }
            now=ch[now][id];
        }
        val[now]=x;
    }
    int work(int x){
        int now=0;
        for(int i=30;i>=0;i--){
            int id=(x&(1<<i))?0:1;
            if (ch[now][id])
                now=ch[now][id];
            else now=ch[now][id^1];
        }
        return val[now];
    }
};
