struct bit{
    int t[32003];
    int n;
    bit(){
        memset(t,0,sizeof(t));
    }
    inline int lowbit(int x){
        return (x&(-x));
    }
    int sum(int x){
        int ret=0;
        for(int i=x;i>0;i-=lowbit(i))
            ret+=t[i];
        return ret;
    }
    void add(int p,int v){
        for(int i=p;i<=n;i+=lowbit(i))
            t[i]+=v;
        //for(int i=1;i<=n;i++)
        	//printf("%d ",t[i]);
    }
};
