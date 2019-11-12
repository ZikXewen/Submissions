#include <bits/stdc++.h>
#define long long long
#define all(x) (x).begin(), (x).end()
using namespace std;
const int X = 3e5 + 5;
const long INF = 1e18 + 1e16;
int N, ar[X], in[X], out[X], rev[X], cd[X];
long sm[X], an = INF, sum;
vector<int> g[X];
set<long> st;
void ans(long u, long v, long w){ if(u && v && w) an = min(an, max({u, v, w}) - min({u, v, w})); }
void dfs(int u, int p){
	static int run = 0;
	rev[in[u] = ++run] = u;
	if(p) g[u].erase(find(all(g[u]), p));
	sm[u] = ar[u], cd[u] = 1;
	for(int &v: g[u]) {
		dfs(v, u), sm[u] += sm[v], cd[u] += cd[v];
		if(cd[v] > cd[g[u][0]]) swap(v, g[u][0]);
	}
	out[u] = run;
}
void sol(int u, bool del){
	for(int v: g[u]) if(v != g[u][0]) sol(v, 1);
	if(g[u].size()) sol(g[u][0], 0);
	for(int v: g[u]) if(v != g[u][0]){
		for(int i = in[v]; i <= out[v]; ++i){
			auto it = st.upper_bound((sum - sm[rev[i]]) >> 1);
			if(it != st.end()) ans(sum - sm[rev[i]] - *it, sm[rev[i]], *it);
			if(it != st.begin()) --it, ans(sum - sm[rev[i]] - *it, sm[rev[i]], *it);
		}
		for(int i = in[v]; i <= out[v]; ++i) st.emplace(sm[rev[i]]);
	}
	st.emplace(sm[u]);
	auto it = st.upper_bound(sm[u] >> 1);
	if(it != st.end()) ans(sum - sm[u], sm[u] - *it, *it);
	if(it != st.begin()) --it, ans(sum - sm[u], sm[u] - *it, *it);
	if(del) st.clear();
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for(int i = 1; i <= N; ++i) cin >> ar[i], sum += ar[i];
	for(int i = 1, u, v; i < N; ++i) cin >> u >> v, g[u].emplace_back(v), g[v].emplace_back(u);
	dfs(1, 0), sol(1, 0); cout << an;
}
