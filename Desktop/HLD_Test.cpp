#include<bits/stdc++.h>
using namespace std;
const int MXN = 10005;
int N, pa[MXN], de[MXN], cd[MXN], rt[MXN], spe[MXN], pos[MXN], idx;
// parents, depth, child, root, special, position, running index
vector<int> g[MXN];
pair<int, int> ed[MXN];
void dfs(int u, int p){
	pa[u] = p;
	de[u] = de[p] + 1;
	cd[u] = 1;
	if(g[u].size() == 1) return;
	spe[u] = (g[u][0] == p)? g[u][1] : g[u][0];
	for(int i : g[u]) if(i != p){
		dfs(i, u);
		cd[u] += cd[i];
		if(cd[i] > cd[spe[u]]) spe[u] = i;
	}
}
void hld(int u){
	pos[u] = ++idx;
	if(spe[pa[u]] != u) rt[u] = u;
	else rt[u] = rt[pa[u]];
	if(g[u].size() == 1) return;
	hld(spe[u]);
	for(int i : g[u]) if(i != pa[u] && i != spe[u]) hld(i);
}
int main(){
	scanf("%d",&N);
	for(int i = 1, u, v, w; i < N; i++){
		scanf("%d %d", &u, &v);
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	dfs(1, 0);
	hld(1);
	for(int i = 1; i <= N; i++) cout << pos[i] << ' ';
}
/*
12
1 2
1 3
2 4
2 5
3 6
3 7
5 8
5 9
7 10
7 11
9 12
*/