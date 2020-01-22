#include <bits/stdc++.h>
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;
const int X = 1e4 + 5;
int N, M, an;
bool vs[X];
int ans[X], mm[X][2];
vector<ii> g[X];
vector<iii> ed;
int dfs(int u, int p, bool can){
	if(mm[u][can]) return mm[u][can];
	int ret = 0, reti = 0;
	for(auto [v, w]: g[u]) if(v != p) reti += (ans[v] = dfs(v, u, !vs[v]));
	if(can) for(auto [v, w]: g[u]) if(v != p && !vs[v]) ret = max(ret, dfs(v, u, 0) + w - ans[v]);
	return mm[u][can] = reti + ret;
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;
	for(int i = 1, u, v, w; i < N; ++i) cin >> u >> v >> w, g[u].emplace_back(v, w), g[v].emplace_back(u, w);
	for(int i = 0, u, v, w; i < M; ++i) cin >> u >> v >> w, ed.emplace_back(u, v, w);
	for(int i = 0; i < 1 << M; ++i){
		int impos = 0, init = 0;
		memset(vs, 0, sizeof vs); 
		memset(mm, 0, sizeof mm);
		for(int j = 0; j < M; ++j){
			if((i & (1 << j)) == 0) continue;
			auto [u, v, w] = ed[j];
			if(vs[u] || vs[v]) {impos = 1; break;}
			vs[u] = vs[v] = 1, init += w;
		}
		if(impos) continue;
		an = max(an, init + dfs(1, 0, !vs[1]));
	}
	cout << an;
}
