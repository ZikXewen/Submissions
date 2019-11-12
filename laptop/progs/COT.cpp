#include <bits/stdc++.h>
using namespace std;
class tr{ public:
	int w;
	tr *l,*r;
	tr(){ w=0,l=r=this;}
};
const int MXN = 111111;
const int LN = 19;
int N,M,v[MXN],rv[MXN],tab[MXN][LN],lvl[MXN],ct;
tr *ver[MXN]={new tr()}; // INIT
map<int,int> mp;
vector<int> ed[MXN];
void inp(){
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++) {
		scanf("%d",&v[i]);
		mp[v[i]];
		ver[i]=new tr(); // INIT
	}
	for(auto i:mp) mp[i.first]=++ct, rv[ct]=i.first; // COMPRESS
	for(int i=1,a,b;i<N;i++){
		scanf("%d%d",&a,&b);
		ed[a].emplace_back(b);
		ed[b].emplace_back(a);
	}
	lvl[1]=1; // FOR LCA
}
void ud(tr *cr, tr pr,int x,int s,int e){ // UPDATE SEGMENT TREE
	if(s==e) {cr->w=pr.w+1; return;}
	int m=(s+e)>>1;
	if(x<=m){
		cr->l = new tr();
		cr->r = pr.r;
		ud(cr->l,*(pr.l),x,s,m);
	} else{
		cr->r = new tr();
		cr->l = pr.l;
		ud(cr->r,*(pr.r),x,m+1,e);
	}
	cr->w=cr->l->w+cr->r->w;
}
void dfs(int cr,int pr){ // MAKING TREES
	for(int i=1;i<=log2(N);i++) tab[cr][i]=tab[tab[cr][i-1]][i-1]; // FOR LCA
	ud(ver[cr],*ver[pr],mp[v[cr]],0,N);
	for(int i:ed[cr]) if(i!=pr) {
		lvl[i]=lvl[cr]+1; // FOR LCA
		tab[i][0]=cr;
		dfs(i,cr);
	}
}
int lca(int a,int b){
	if(lvl[a]<lvl[b]) swap(a,b);
	for(int i=log2(N);i>=0;i--) if(lvl[tab[a][i]]>=lvl[b]) a=tab[a][i];
	if(a==b) return a;
	for(int i=log2(N)-1;i>=0;i--) if(tab[a][i]!=tab[b][i]) a=tab[a][i],b=tab[b][i];
	return tab[a][0];
}
int que(tr a,tr b,tr c,tr d,int x,int s,int e){ // BSEARCH TO FIND Xth ELEMENT BETWEEN A&B
	if(s>=e) return s;
	int m=(s+e)>>1;
	int k=(a.l->w)+(b.l->w)-(c.l->w)-(d.l->w); // M is Kth ELEMENT
	if(k>=x) return que(*a.l,*b.l,*c.l,*d.l,x,s,m);
	return que(*a.r,*b.r,*c.r,*d.r,x-k,m+1,e);
}
int main(){	
	inp();
	dfs(1,0);
	for(int i=0,a,b,c,d;i<M;i++){
		scanf("%d%d%d",&a,&b,&c);
		d=lca(a,b);
		printf("%d\n",rv[que(*ver[a],*ver[b],*ver[d],*ver[tab[d][0]],c,0,N)]);
	}
//	for(int i=0;i<N;i++) cout << gt(*ver[6],i);
}
	
