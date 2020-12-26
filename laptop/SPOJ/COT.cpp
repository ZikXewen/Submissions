#include <bits/stdc++.h>
using namespace std;
const int X = 1e5 + 5, L = 20;
class node{
	public:
	int va;
	node *l, *r;
	node() = default;
} *tr[X];
int N, M, we[X], p[X][L], ct, lv[X], rv[X];
vector<int> g[X];
map<int, int> mp;
void bd(node *cur = tr[0], int l = 1, int r = X){
	if(l == r) return;
	int m = l + r >> 1;
	bd(cur -> l = new node(), l, m);
	bd(cur -> r = new node(), m + 1, r);
}
void ud(node *cur, node *old, int va, int l = 1, int r = X){
	if(l == r) return cur -> va = old -> va + 1, void();
	int m = l + r >> 1;
	if(m >= va) cur -> r = old -> r, ud(cur -> l = new node(), old -> l, va, l, m);
	else cur -> l = old -> l, ud(cur -> r = new node(), old -> r, va, m + 1, r);
	cur -> va = cur -> l -> va + cur -> r -> va;
}
void dfs(int u = 1){
	for(int i = 1; i < L; ++i) p[u][i] = p[p[u][i - 1]][i - 1];
	ud(tr[u], tr[p[u][0]], mp[we[u]]);
	for(int i: g[u]) if(i != p[u][0])
		p[i][0] = u, lv[i] = lv[u] + 1, dfs(i);
}
int lca(int u, int v){
	if(lv[u] < lv[v]) swap(u, v);
	for(int i = L - 1; i >= 0; --i) if(lv[p[u][i]] >= lv[v]) u = p[u][i];
	if(u == v) return u;
	for(int i = L - 1; i >= 0; --i) if(p[u][i] != p[v][i]) u = p[u][i], v = p[v][i];
	return p[u][0];
}
int fd(node *u, node *v, node *w, node *x, int va, int l = 1, int r = X){
	if(l == r) return l;
	int lef = (u -> l -> va) + (v -> l -> va) - (w -> l -> va) - (x -> l -> va), m = l + r >> 1;
	if(lef < va) return fd(u -> r, v -> r, w -> r, x -> r, va - lef, m + 1, r);
	return fd(u -> l, v -> l, w -> l, x -> l, va, l, m);
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;
	for(int i = 1; i <= N; ++i) cin >> we[i], mp[we[i]];
	for(auto &[u, v]: mp) rv[v = ++ct] = u;
	for(int i = 0; i <= N; ++i) tr[i] = new node();
	bd();
	for(int i = 1, u, v; i < N; ++i)
		cin >> u >> v,
		g[u].emplace_back(v), g[v].emplace_back(u);
	lv[1] = 1; dfs();
	for(int i = 0, u, v, w; i < M; ++i){
		cin >> u >> v >> w;
		int lc = lca(u, v);
		cout << rv[fd(tr[u], tr[v], tr[lc], tr[p[lc][0]], w)] << '\n';
	}
}