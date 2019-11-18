#include <bits/stdc++.h>
#define tu tuple<int, int, int>
#define all(x) (x).begin(), (x).end()
using namespace std;
const int X = 1e4 + 5;
int N, M, vs[X];
vector<int> g[X];
vector<tu> an;
tu st = tu(0, 0, 1e9);
bool dfs(int u, int p){
	if(u == get<0>(st)) {an.emplace_back(p, u, 0); return 1;}
	bool ret = 0; vs[u] = 1;
	for(int v: g[u]) if(!vs[v]) ret |= dfs(v, u); else if(v != p && vs[v] == 1) an.emplace_back(v, u, 0);
	if(ret) an.emplace_back(p, u, 0);
	else an.emplace_back(u, p, 0);
	vs[u] = 2;
	return ret;
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;
	for(int i = 0, u, v, w; i < M; ++i) 
		cin >> u >> v >> w, g[u].emplace_back(v), g[v].emplace_back(u), 
		st = min(st, tu(u, v, w), [](const tu &l, const tu &r){return get<2>(l) < get<2>(r);});
	auto [u, v, w] = st; cout << w << ' ' << 1 << '\n';
	g[u].erase(find(all(g[u]), v)); g[v].erase(find(all(g[v]), u));
	an.emplace_back(u, v, 1), dfs(v, u), an.pop_back();
	assert(an.size() == M);
	for(auto [u, v, w]: an) cout << u << ' ' << v << ' ' << w << '\n';
}
