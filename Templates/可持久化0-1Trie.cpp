struct trie{
	static const int maxw=16;
	static const int maxt=18*100000+1;
	static const int maxv=100001;
	struct node{
		int val,sz;
		int ch[2];
		node(){
			val=sz=ch[0]=ch[1]=0;
		}
		node operator =(const node& rhs){
			val=rhs.val;
			sz=rhs.sz;
			ch[0]=rhs.ch[0];
			ch[1]=rhs.ch[1];
			return *this;
		}
	};
	trie(){
		ver=cur=0;
	}
	int ver,cur;
	node t[maxt];
	int root[maxv];
	void ins(int x){
		t[++cur]=t[root[ver]];
		t[cur].sz++;
		root[++ver]=cur;
		int now=cur;
		for(int i=maxw;i>=0;i--){
			int v=(x&(1<<i))?1:0;
			cur++;
			t[cur]=t[t[now].ch[v]];
			t[cur].sz++;
			t[now].ch[v]=cur;
			now=cur;
		}
		t[now].val=x;
	}
	int query(int l,int r,int k){
		int lnow=root[l-1],rnow=root[r];
		for(int i=maxw;i>=0;i--){
			int sz=t[t[rnow].ch[0]].sz-t[t[lnow].ch[0]].sz;
			if(sz>=k){
				lnow=t[lnow].ch[0];
				rnow=t[rnow].ch[0];
			}
			else {
				k-=sz;
				lnow=t[lnow].ch[1];
				rnow=t[rnow].ch[1];
			}
		}
		return t[rnow].val;
	}
};
