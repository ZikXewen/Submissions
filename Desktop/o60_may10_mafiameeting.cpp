#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;
const int X = 2e5 + 5;
int N, M, Q, ct, low[X], pre[X], anc[X][(int) log2(X) + 1], lv[X], ds[X], id[X];
bitset<X> ap, vs;
vector<vi> g(X), cc;
vi sz;
stack<int> stk;
void grp(int u = 1, int p = 0){
	int cd = 0;
	low[u] = pre[u] = ++ct;
	stk.emplace(u);
	for(int v: g[u]){
		if(!pre[v]){
			grp(v, u); ++cd;
			low[u] = min(low[u], low[v]);
			if((p && low[v] >= pre[u]) || (!p && cd > 1)){
				ap[u] = 1;
				cc.emplace_back(vi(1, u));
				while(cc.back().back() != v) cc.back().emplace_back(stk.top()), stk.pop();
			}
		} else if(v != p) low[u] = min(low[u], pre[v]);
	}
}
void bct(){
	g.clear(); ct = 0;
	g.emplace_back(vi());
	sz.emplace_back(0);
	for(int i = 1; i <= N; ++i) if(ap[i]) id[i] = ++ct, g.emplace_back(vi()), sz.emplace_back(-1);
	for(vi i: cc){
		g.emplace_back(vi()), sz.emplace_back(i.size()); ++ct;
		for(int v: i)
			if(ap[v]) g[ct].emplace_back(id[v]), g[id[v]].emplace_back(ct);
			else id[v] = ct;
	}
}
void dfs(int u = 1, int p = 0){
	vs[u] = 1;
	for(int v: g[u]) if(!vs[v]) ds[v] = ds[u] + sz[v], dfs(v, u);
}
void plca(int u = 1, int p = 0){
	anc[u][0] = p, lv[u] = lv[p] + 1;
	for(int i = 1; i <= log2(ct); ++i) anc[u][i] = anc[anc[u][i - 1]][i - 1];
	for(int v: g[u]) if(v != p) plca(v, u);
}
int lca(int u, int v){
	if(lv[u] < lv[v]) swap(u, v);
	for(int i = log2(ct); i >= 0; --i) if(lv[anc[u][i]] >= lv[v]) u = anc[u][i];
	if(u == v) return u;
	for(int i = log2(ct); i >= 0; --i) if(anc[u][i] != anc[v][i]) u = anc[u][i], v = anc[v][i];
	return anc[u][0];
}
int gt(int u){return ds[u] + (sz[u] == -1);}
int calc(int u, int v){
	int w = lca(u, v);
	return gt(u) + gt(v) - (gt(w) << 1) + abs(sz[w]) - 2;
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M >> Q;
	for(int i = 0, u, v; i < M; ++i) cin >> u >> v, g[u].emplace_back(v), g[v].emplace_back(u);
	grp();
	if(stk.size()) cc.emplace_back(vi());
	while(stk.size()) cc.back().emplace_back(stk.top()), stk.pop();
	bct(); vs[0] = 1, ds[1] = sz[1], dfs(); plca();
	for(int i = 0, u, v; i < Q; ++i) cin >> u >> v, cout << calc(id[u], id[v]) << '\n';
}