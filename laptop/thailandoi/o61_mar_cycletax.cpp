#include <bits/stdc++.h>
#define tu tuple<int, int, int>
#define all(x) (x).begin(), (x).end()
using namespace std;
const int X = 1e4 + 5;
int N, M;
bool vs[X], ps[X][X];
vector<int> g[X];
vector<tu> an;
tu st = tu(0, 0, 1e9);
bool dfs(int u, int p){
	if(u == get<0>(st)) {an.emplace_back(p, u, 0); return 1;}
	bool ret = 0; vs[u] = 1;
	for(int v: g[u]) if(!ps[u][v]){
		ps[u][v] = ps[v][u] = 1;
		if(!vs[v]) ret |= dfs(v, u);
		else an.emplace_back(v, u, 0);
	}
	if(ret) an.emplace_back(p, u, 0);
	else an.emplace_back(u, p, 0), cout << p << u;
	return ret;
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;
	for(int i = 0, u, v, w; i < M; ++i) {
		cin >> u >> v >> w, g[u].emplace_back(v), g[v].emplace_back(u);
		if(w < get<2>(st)) st = tu(u, v, w);
	}
	auto [u, v, w] = st; cout << w << " 1\n";
	ps[u][v] = ps[v][u] = 1; dfs(v, u); get<2>(an.back()) = 1;
	for(auto [u, v, w]: an) cout << u << ' ' << v << ' ' << w << '\n';
}
