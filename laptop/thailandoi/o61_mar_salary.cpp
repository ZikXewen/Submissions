#include <bits/stdc++.h>
using namespace std;
const int X = 1e5 + 5;
int N, in[X], p[X];
vector<int> g[X];
multiset<int> s[X];
void dfs(int u){
	for(int &v: g[u]) {dfs(v); if(s[p[v]].size() > s[p[g[u][0]]].size()) swap(v, g[u][0]);}
	if(g[u].size()) p[u] = p[g[u][0]];
	for(int v: g[u]) if(v != g[u][0]) for(int k: s[p[v]]) s[p[u]].emplace(k);
	auto it = upper_bound(s[p[u]].begin(), s[p[u]].end(), in[u]);
	if(it != s[p[u]].end()) s[p[u]].erase(it);
	s[p[u]].emplace(in[u]);
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for(int i = 0; i < N; ++i) cin >> in[i], p[i] = i;
	for(int i = 1, u, v; i < N; ++i) cin >> u >> v, g[u].emplace_back(v);
	dfs(0);
	cout << N - s[p[0]].size();
}