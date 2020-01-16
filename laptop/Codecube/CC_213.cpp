#include <bits/stdc++.h>
#define long long long
#define ii pair<long, int>
using namespace std;
const int X = 2e5 + 5;
int N, M, S, E, Q;
vector<long> ds, de, dis;
vector<ii> g[X];
vector<int> ve;
void dijk(const vector<int> &s, vector<long> &ou){
	priority_queue<ii, vector<ii>, greater<ii>> q;
	ou.assign(N + 1, (long) 1e17);
	for(int i: s) q.emplace(ou[i] = 0, i);
	while(q.size()){
		auto [u, v] = q.top(); q.pop();
		if(ou[v] < u) continue;
		for(auto [po, va]: g[v]) if(u + va < ou[po]) q.emplace(ou[po] = u + va, po);
	}
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M >> S >> E;
	for(int i = 0, u, v, w; i < M; ++i)
		cin >> u >> v >> w, g[u].emplace_back(v, w), g[v].emplace_back(u, w);
	dijk({S}, ds), dijk({E}, de);
	for(int i = 1; i <= N; ++i) if(ds[i] + de[i] == ds[E]) ve.emplace_back(i);
	dijk(ve, dis); cin >> Q;
	for(int i = 0, u; i < Q; ++i) cin >> u, cout << dis[u] << '\n';
}
