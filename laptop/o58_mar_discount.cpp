#include <bits/stdc++.h>
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define x first
#define y second
using namespace std;
const int X = 2e4 + 5;
int N, M, p[X], an = 2e9, lv[X], pa[X][15], mx[X][15];
vector<iii> ed, un;
vector<ii> g[X];
int fd(int u) { return p[u] = p[u] == u ? u : fd(p[u]); }
void plca(int u, int pu) {
	lv[u] = lv[pu] + 1; pa[u][0] = pu;
	for(int i = 1; i <= log2(N); i++) pa[u][i] = pa[pa[u][i - 1]][i-1], mx[u][i] = max(mx[u][i - 1], mx[pa[u][i - 1]][i-1]);
	for(ii i: g[u]) if(i.x != pu) mx[i.x][0] = i.y, plca(i.x, u);
}
int lca(int u, int v) {
	int ret = 0;
	if(lv[u] < lv[v]) swap(u, v);
	for(int i = log2(N); i >= 0; i--) if(lv[pa[u][i]] >= lv[v]) ret = max(ret, mx[u][i]), u = pa[u][i]; // Care update order!!
	if(u == v) return ret;
	for(int i = log2(N); i >= 0; i--) if(pa[u][i] != pa[v][i]) ret = max(ret, max(mx[u][i], mx[v][i])), u = pa[u][i], v = pa[v][i]; // Care update order!
	return max(ret, max(mx[u][0], mx[v][0]));
}
int main() {
	scanf("%d %d", &N, &M);
	iota(p, p + N + 1, 0);
	for(int i = 0, u, v, w; i < M; i++) scanf("%d %d %d", &u, &v, &w), ed.emplace_back(w, u + 1, v + 1);
	sort(ed.begin(), ed.end());
	for(iii i: ed) {
		int u = fd(get<1>(i)), v = fd(get<2>(i));
		if(u == v) un.emplace_back(i);
		else p[u] = v, g[get<2>(i)].emplace_back(get<1>(i), get<0>(i)), g[get<1>(i)].emplace_back(get<2>(i), get<0>(i));
	}
	plca(1, 0);
	for(iii i: un) an = min(an, get<0>(i) - lca(get<1>(i), get<2>(i)));
	printf("%d", an + 1);
}
