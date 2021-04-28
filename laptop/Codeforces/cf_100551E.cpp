#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;
const int X = 1e5 + 5;
int p[X], lef[X], N, M, Q, ct;
bool an[X];
ii g[X];
vector<ii> lv[X], rv[X];
stack<ii> stk;
int fd(int u){return p[u] < 0? u : fd(p[u]);}
void un(int id){
	auto [u, v] = g[id];
	u = fd(u), v = fd(v);
	if(u == v) return;
	if(p[u] < p[v]) swap(u, v);
	stk.emplace(u, p[u]); stk.emplace(v, p[v]);
	p[v] += p[u]; p[u] = v; ++ct;
}
void sol(int l = 0, int r = Q){
	if(l == r) return (an[l] = (ct == N - 1)), void();
	int tostk = stk.size(), toct = ct, m = (l + r) >> 1;
	for(int i = l; i <= m + 1; ++i) for(auto [u, v]: rv[i]) if(u >= r) un(v);
	sol(m + 1, r);
	while(stk.size() > tostk){ auto [u, v] = stk.top(); stk.pop(); p[u] = v;} ct = toct;
	for(int i = m; i <= r; ++i) for(auto [u, v]: lv[i]) if(u <= l) un(v);
	sol(l, m); 
	while(stk.size() > tostk){ auto [u, v] = stk.top(); stk.pop(); p[u] = v;} ct = toct;
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("disconnected.in", "r", stdin);
	freopen("disconnected.out", "w", stdout);
	cin >> N >> M;
	for(int i = 1, u, v; i <= M; ++i) cin >> u >> v, g[i] = ii(u, v);
	cin >> Q;
	for(int i = 0, u; i < Q; ++i){
		cin >> u;
		for(int j = 0, v; j < u; ++j) {
			cin >> v;
			if(lef[v] != i)
				lv[i - 1].emplace_back(lef[v], v),
				rv[lef[v]].emplace_back(i - 1, v);
			lef[v] = i + 1;
		}
	}
	for(int i = 1; i <= M; ++i) if(lef[i] != Q)
		lv[Q].emplace_back(lef[i], i),
		rv[lef[i]].emplace_back(Q, i);
	memset(p, -1, sizeof p);
	sol();
	for(int i = 0; i < Q; ++i) cout << (an[i]? "Connected\n" : "Disconnected\n");
}