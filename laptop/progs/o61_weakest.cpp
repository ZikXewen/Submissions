#include<bits/stdc++.h>
using namespace std;
const int MXN = 1e5+5;
const int MXI = 2e9;
class ii{public: int v,w;};
int N,lvl[MXN];
int Q,K,M,A,B;
vector<vector<ii>> tab;
vector<ii> ed[MXN];
void inp(){
	int _u,_v;
	scanf("%d",&N);
	for(int i=1;i<N;i++){
		scanf("%d%d",&_u,&_v);
		ed[_u].push_back({i,_v});
	}
	scanf("%d%d%d%d%d",&Q,&K,&M,&A,&B);
	tab.assign(N,vector<ii>(log2(N)+1,{0,MXI}));
}
void pre(int u,int p){
	for(int i=1;i<=log2(N);i++){
		tab[u][i].v=tab[tab[u][i-1].v][i-1].v;
		tab[u][i].w=min(tab[u][i-1].w,tab[tab[u][i-1].v][i-1].w);
	}
	for(ii v:ed[u]) if(v.v!=p){
		lvl[v.v]=lvl[u]+1;
		tab[v.v][0].v=u;
		tab[v.v][0].w=v.w;
		pre(v.v,u);
	}
}
int lca(int u,int v){
	if(u==v) return 0;
	int ret=MXN;
	if(lvl[u]<lvl[v]) swap(u,v);
	for(int i=log2(N);i>=0;i--) if(lvl[tab[u][i].v]>=lvl[v]){
		ret=min(ret,tab[u][i].w);
		u=tab[u][i].v;
	}
	if(u==v) return ret;
	for(int i=log2(N);i>=0;i--) if(tab[u][i].v!=tab[v][i].v){
		ret=min(ret,min(tab[u][i].w,tab[v][i].w));
		u=tab[u][i].v; v=tab[v][i].v;
	}
	return min(ret,min(tab[u][0].w,tab[v][0].w));
}
int main(){
	inp();
	pre(0,-1);
	while(Q--){
		int RI = lca(A,B);printf("%d\n",RI);
		A=B; B=((B*K)+RI)%M%N;
	}
}
