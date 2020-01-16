#include <bits/stdc++.h>
#define ii pair<int, int>
#define x first
#define y second
using namespace std;
const int X = 1 << 17;
const int IN = 1e9;
int K, L, Q, pa[int(log2(X)) + 5][X], lv[X], di[X][10];
vector<int> g[X];
vector<ii> ed;
void plca(int u = 1, int p = 0){
	lv[u] = lv[p] + 1;
	pa[0][u] = p;
	for(int i = 1; i <= K; i++) pa[i][u] = pa[i-1][pa[i-1][u]];
	for(int i: g[u]) if(i != p) plca(i, u);
}
int lca(int u, int v){
	if(lv[u] < lv[v]) swap(u, v);
	for(int i = K; i + 1; i--) if(lv[pa[i][u]] >= lv[v]) u = pa[i][u];
	if(u == v) return u;
	for(int i = K; i + 1; i--) if(pa[i][u] != pa[i][v]) u = pa[i][u], v = pa[i][v];
	return pa[0][u];
}
void dijk(int s, int ar){
	queue<ii> q;
	q.emplace(0, s);
	while(q.size()){
		ii cr = q.front(); q.pop();
		for(int i: g[cr.y]) if(!di[i][ar] && i!= s) di[i][ar] = cr.x + 1, q.emplace(cr.x + 1, i);
	}
}
int main(){
	scanf("%d %d %d", &K, &L, &Q);
	for(int i = 0; i < (1 << (K - 1)); i++) {
		g[i].emplace_back(i << 1);
		g[i << 1].emplace_back(i);
		g[i].emplace_back(i << 1 | 1);
		g[i << 1 | 1].emplace_back(i);
		g[i + (1 << K)].emplace_back((i << 1) + (1 << K));
		g[(i << 1) + (1 << K)].emplace_back(i + (1 << K));
		g[i + (1 << K)].emplace_back((i << 1 | 1) + (1 << K));
		g[(i << 1 | 1) + (1 << K)].emplace_back(i + (1 << K));
	}
	plca();
	for(int i = 0, u, v; i < L; i++) {
		scanf("%d %d", &u, &v);
		g[u].emplace_back(v);
		g[v].emplace_back(u);
		ed.emplace_back(u, v);
	}
	for(int i = 0; i < ed.size(); i++) dijk(ed[i].x, i << 1), dijk(ed[i].y, i << 1 | 1);
	for(int u, v; Q; Q--){
		int an = IN;
		scanf("%d %d", &u, &v);
		for(int i = 0; i < ed.size(); i++) an = min(an, min(di[u][i << 1] + di[v][i << 1 | 1], di[v][i << 1] + di[u][i << 1 | 1]) + 1);
		if(u >= (1 << K) && v >= (1 << K)) u -= (1 << K), v -= (1 << K);
		if(u < (1 << K) && v < (1 << K)) an = min(an, lv[u] + lv[v] - (lv[lca(u, v)] << 1));
		printf("%d\n", an);
	}
}
