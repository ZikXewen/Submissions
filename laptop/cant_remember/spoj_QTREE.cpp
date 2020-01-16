#include <bits/stdc++.h>
#define x first
#define y second
#define ii pair<int,int>
using namespace std;
const int MXN = 1e4+10;
int T,N;
int s,t,lc;
char tp[7];
int dep[MXN],par[int(log2(MXN))][MXN],rt[MXN],cd[MXN],ed[MXN],hvy[MXN],pos[MXN];
vector<ii> g[MXN];
ii ted[MXN];
void prep(int u,int p){
	for(int i=1;i<log2(N);i++) par[i][u]=par[i-1][par[i-1][u]];
	cd[u]=1, dep[u]=dep[p]+1;
	for(ii &v:g[u]) if(v.x!=p){
		par[0][v.x]=u;
		ed[v.x]=v.y;
		prep(v.x,u);
		cd[u]+=cd[v.x];
		if(cd[v.x]>cd[hvy[u]]) hvy[u]=v.x; 
	}
}
void dfs(int u){
	static int idx=1;
	if(!par[0][u]||hvy[par[0][u]]!=u) rt[u]=u;
	else rt[u]=rt[par[0][u]];
	pos[u]=idx++;
	for(ii v:g[u]) if(v.x!=par[0][u]) dfs(v.x);
}
int lca(){
	if(dep[s]<dep[t]) swap(s,t);
	for(int i=log2(N);i>=0;i--) if(dep[par[i][s]]>=dep[t]) s=par[i][s];
	if(s==t) return s;
	for(int i=log2(N);i>=0;i--) if(par[i][s]!=par[i][t]) s=par[i][s],t=par[i][t];
	return par[0][s];
}
void ud(int s,int t){
	
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for(int i=1,u,v,w;i<N;i++) {
			scanf("%d%d%d",&u,&v,&w);
			g[u].emplace_back(v,w);
			g[v].emplace_back(u,w);
			ted[i]={u,v};
		}
		prep(1,0);
		dfs(1);
		for(int i=0;i<=N;i++) cout << rt[i] << ' ';
		while(scanf("%s",tp) && tp[0]!='D' ){
			cout << tp[0];
			scanf("%d%d",&s,&t);
			if(tp[0]=='Q') lc=lca(), printf("%d",/*max(que(s,lc),que(t,lc))*/lc);
			else{
				if(dep[ted[s].x]<dep[ted[s].y]) s=ted[s].y;
				else s=ted[s].x;
				if(rt[s]!=s) ud(s,t);
			}
		}
	}
}
/*
1
13
1 2 1
1 3 1
2 4 1
2 5 1
3 6 1
3 7 1
3 8 1
4 9 1
4 10 1
7 11 1
7 12 1
8 13 1
*/
