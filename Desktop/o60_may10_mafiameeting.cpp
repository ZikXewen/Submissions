#include <bits/stdc++.h>
using namespace std;
const int X = 1e5 + 5;
int N, M, Q, ct, low[X], pre[X];
bool ap[X];
vector<vector<int>> g(X), cc;
vector<int> sz;
stack<int> stk;
void grp(int u = 1, int p = 0){
	low[u] = pre[u] = ++ct;
	stk.emplace(u)
	for(int v: g[u]){
		if(!pre[v]){
			grp(v, u);
			low[u] = min(low[u], low[v]);
			if(low[v] >= pre[u]){
				ap[u] = 1;
				cc.emplace_back(vi(1, u));
				do cc.back().emplace_back(stk.top()), stk.pop(); while(stk.top() != v);
			}
		} else if(v != p) low[u] = min(low[u], pre[v]);
	}
}
void bct(){
	g.clear(); ct = 0;
	g.emplace_back(vi());
	sz.emplace_back(0);
	for(int i = 1; i <= N; ++i) if(ap[i]) id[i] = ++ct, g.emplace_back(vi()), sz.emplace_back(1);
	for(vi i: cc){
		g.emplace_back(vi()), sz.emplace_back(i.size()); ++ct;
		for(int v: i)
			if(ap[v]) g[ct].emplace_back(id[v]), g[id[v]].emplace_back(ct)
			else id[v] = ct;
	}
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M >> Q;
	for(int i = 0, u, v; i < M; ++i) cin >> u >> v, g[u].emplace_back(v), g[v].emplace_back(u);
	grp(); bct();
	for(int i = 0, u, v; i < Q; ++i) cin >> u >> v;
}