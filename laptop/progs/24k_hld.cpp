#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> g[n];
int dep[n],par[n],rt[n];
int sz[n];
void dfs1(int u,int p){
	if(p) g[u].erase(find(g[u].begin(),g[u].end(),p));
	dep[u]=dep[p]+1; par[u]=p; sz[u]=1;
	for(int &v:g[u]){
		dfs1(v,u);
		sz[u]+=sz[v];
		if(sz[v]>sz[g[u][0]]) swap(v,g[u][0]);
	}
}
void dfs2(int u){
	static int idx = 1;
	if(!par[u]||g[par[u]][0]!=u) rt[u]=u;
	else rt[u]=rt[par[u]	];
	pos[u]=idx++;
	for(int v:g[u]) if(v!=par[u])dfs2(v);
}
int main(){
	cin >> n >> m;
	for(int i=0,u,v;i<m;i++){
		cin >> u >> v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	dfs1(1,0);
	dfs2(1);
}
