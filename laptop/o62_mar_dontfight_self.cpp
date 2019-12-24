#include <bits/stdc++.h>
#define long long long
#define all(x) (x).begin(), (x).end()
using namespace std;
const int X = 3e5 + 5;
const long INF = 1e18 + 1e16;
int ar[X], N, run, cd[X], rev[X], in[X], out[X];
vector<int> g[X];
set<long> st;
long an = INF, tot, sm[X];
void ans(long u, long v, long w){ if(u and v and w) an = min(an, max({u, v, w}) - min({u, v, w})); }
void dfs(int u, int p){
	rev[in[u] = ++run] = u, cd[u] = 1, sm[u] = ar[u];
	if(p) g[u].erase(find(all(g[u]), p));
	for(int &v: g[u]){
		dfs(v, u), cd[u] += cd[v], sm[u] += sm[v];
		if(cd[v] > cd[g[u][0]]) swap(v, g[u][0]);
	}
	out[u] = run;
}
void sol(int u, bool del){
	for(int i = g[u].size() - 1; i >= 0; --i) sol(g[u][i], i);
	for(int v: g[u]) if(v != g[u][0]){
		for(int i = in[v]; i <= out[v]; ++i){
			long cr = sm[rev[i]];
			auto it = st.upper_bound((tot - cr) >> 1);
			if(it != st.end()) ans(*it, tot - cr, tot - cr - *it);
			if(it != st.begin()) --it, ans(*it, tot - cr, tot - cr - *it);
		}
		for(int i = in[v]; i <= out[v]; ++i) st.emplace(sm[rev[i]]);
	}
	st.emplace(sm[u]);
	auto it = st.upper_bound(sm[u] >> 1);
	if(it != st.end()) ans(*it, tot - sm[u], sm[u] - *it);
	if(it != st.begin()) --it, ans(*it, tot - sm[u], sm[u] - *it);
	if(del) st.clear();
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for(int i = 1; i <= N; ++i) cin >> ar[i], tot += ar[i];
	for(int i = 1, u, v; i < N; ++i) cin >> u >> v, g[u].emplace_back(v), g[v].emplace_back(u);
	dfs(1, 0), sol(1, 0), cout << an;
}
