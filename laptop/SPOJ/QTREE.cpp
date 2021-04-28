#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;
const int X = 1e4 + 5;
int T, N, p[X], lv[X], rt[X], pos[X], rpos[X], etp[X], id, st[X << 2], ed[X][2]; //etp = Edge to Parent
vector<ii> g[X];
int pre(int u = 1){
	int cd = 1, mx = 0;
	for(int i = 0; i < g[u].size(); ++i){
		auto [v, w] = g[u][i];
		if(v == p[u]) continue;
		p[v] = u, lv[v] = lv[u] + 1, etp[v] = w;
		int tem = pre(v); cd += tem;
		if(tem > mx) swap(g[u][0], g[u][i]), mx = tem; // FOR HLD
	}
	return cd;
}
void dec(int u = 1){
	pos[u] = ++id, rpos[id] = u;
	rt[u] = ((u != 1 and g[p[u]][0].first == u)? rt[p[u]] : u); // SET ROOT
	for(auto [v, w]: g[u]) if(v != p[u]) dec(v);
}
void bd(int l = 1, int r = id, int x = 1){
	if(l == r) return st[x] = etp[rpos[l]], void();
	int m = (l + r) >> 1;
	bd(l, m, x << 1), bd(m + 1, r, x << 1 | 1);
	st[x] = max(st[x << 1], st[x << 1 | 1]);
}
void ud(int po, int va, int l = 1, int r = id, int x = 1){
	if(l == r) return st[x] = va, void();
	int m = (l + r) >> 1;
	if(po <= m) ud(po, va, l, m, x << 1);
	else ud(po, va, m + 1, r, x << 1 | 1);
	st[x] = max(st[x << 1], st[x << 1 | 1]);
}
int gt(int u, int v, int l = 1, int r = id, int x = 1){
	if(v < l or u > r) return INT_MIN;
	if(u <= l and v >= r) return st[x];
	int m = (l + r) >> 1;
	return max(gt(u, v, l, m, x << 1), gt(u, v, m + 1, r, x << 1 | 1));
}
int que(int u, int v){
	int ret = INT_MIN;
	while(rt[u] != rt[v]){
		if(lv[rt[u]] < lv[rt[v]]) swap(u, v);
		ret = max(ret, gt(pos[rt[u]], pos[u])), u = p[rt[u]];
	}
	if(lv[u] < lv[v]) swap(u, v);
	return max(ret, gt(pos[v] + 1, pos[u]));
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T; while(T--){
		id = 0;
		for(int i = 0; i < X; ++i) g[i].clear();
		cin >> N;
		for(int i = 1, u, v, w; i < N; ++i) cin >> u >> v >> w, g[u].emplace_back(v, w), g[v].emplace_back(u, w), ed[i][0] = u, ed[i][1] = v;
		pre(); dec(); bd();
		while(1){
			string str; int u, v;
			cin >> str; if(str[0] == 'D') break;
			cin >> u >> v;
			if(str[0] == 'C') ud(pos[(lv[ed[u][0]] > lv[ed[u][1]])? ed[u][0] : ed[u][1]], v);
			else cout << que(u, v) << '\n';
		}
	}
}
/*
1
8
1 2 1
1 3 1
2 4 2
2 5 2
3 6 2
5 7 3
5 8 3
Q 1 6
Q 2 3
Q 7 4
Q 4 5
Q 2 6
C 7 1
Q 3 8
C 4 1
Q 8 6
Q 3 8
*/