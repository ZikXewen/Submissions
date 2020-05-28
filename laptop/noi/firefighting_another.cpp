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
		me((ty? ov : un), va);
	}
	bl ret;
	if(ov >= un){
		if(ov >= ds) ret = {1, ov - ds};
		else ret = {0, 0};
	}
	else{
		if(un + ds <= K) ret = {0, un + ds};
		else{
			an.emplace_back(u);
			if(K >= ds) ret = {1, K - ds};
			else ret = {0, 0};
		}
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> K;
	for(int i = 1, u, v, w; i < N; ++i) cin >> u >> v >> w, g[u].emplace_back(v, w), g[v].emplace_back(u, w);
	dfs(1, 0, LLONG_MAX >> 2);
	cout << an.size() << '\n';
	for(int i: an) cout << i << ' ';
}