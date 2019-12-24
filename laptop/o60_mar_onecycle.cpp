#include <bits/stdc++.h>
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;
const int X = 3e3 + 5, LX = 12;
int N, p[X], ju[X][LX], di[X][LX], lv[X];
vector<iii> ed, ot, an;
vector<ii> g[X];
int fd(int u){return p[u] = (p[u] == u)? u : fd(p[u]);}
void dfs(int u){
	for(int i = 1; i <= log2(N); i++) ju[u][i] = ju[ju[u][i - 1]][i - 1], di[u][i] = di[u][i - 1] + di[ju[u][i - 1]][i - 1];
	for(auto [v, w]: g[u]) if(v != ju[u][0]) ju[v][0] = u, di[v][0] = w, lv[v] = lv[u] + 1, dfs(v);
}
int lca(int u, int v){
	int ret = 0;
	if(lv[u] < lv[v]) swap(u, v);
	for(int i = log2(N); i >= 0; i--) if(lv[ju[u][i]] >= lv[v]) ret += di[u][i], u = ju[u][i];
	if(u == v) return ret;
	for(int i = log2(N); i >= 0; i--) if(ju[u][i] != ju[v][i]) ret += di[u][i] + di[v][i], u = ju[u][i], v = ju[v][i];
	return ret + di[u][0] + di[v][0];
}
int main(){
	scanf("%d", &N);
	for(int i = 1, u; i <= N; ++i) for(int j = 1; j <= N; ++j) if(i != j) scanf("%d", &u), ed.emplace_back(u, i, j);
	sort(ed.begin(), ed.end()); iota(p, p + N + 1, 0);
	for(auto [w, u, v]: ed){
		int uu = fd(u), vv = fd(v);
		if(uu != vv) p[uu] = vv, g[u].emplace_back(v, w), g[v].emplace_back(u, w), an.emplace_back(u, v, w);
		else ot.emplace_back(w, u, v);
	}
	dfs(1);
	for(auto [w, u, v]: ot) if(lca(u, v) != w) {an.emplace_back(u, v, w); break;}
	sort(an.begin(),an.end());
	for(auto [u, v, w]: an) printf("%d %d %d\n", u, v, w);
}
