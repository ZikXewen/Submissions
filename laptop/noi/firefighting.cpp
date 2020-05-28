#include <bits/stdc++.h>
#define long long long
#define ii pair<int, int>
#define bl pair<bool, long>
#define me(u, v) ((u) = max((u), (v)))
using namespace std;
const int X = 3e5 + 5;
int N; long K;
vector<ii> g[X];
vector<int> an;
bl dfs(int u, int p, long ds){ 
	long ov = LLONG_MIN, un = 0;
	for(auto [v, w]: g[u]) if(v != p) {
		auto [ty, va] = dfs(v, u, w);
		if(ty) ov = max(ov, va);
		else un = max(un, va);
	}
	bool rb; long rl;
	if(ov >= un) rb = 1, rl = ov - ds;
	else rb = 0, rl = un + ds;
	
	if(!rb && rl > K) an.emplace_back(u), rb = 1, rl = K - ds;
	if(rb && rl < 0) rb = 0, rl = 0;
	return {rb, rl};
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> K;
	for(int i = 1, u, v, w; i < N; ++i) cin >> u >> v >> w, g[u].emplace_back(v, w), g[v].emplace_back(u, w);
	dfs(1, 0, LLONG_MAX >> 2);
	cout << an.size() << '\n';
	for(int i: an) cout << i << ' ';
}