#include <bits/stdc++.h>
using namespace std;
const int MXN = 2e5+5;
class iii{
	public: int u, v, w;
	iii(int _u, int _v, int _w) { u = _u, v = _v, w = _w; }
	bool operator<(const iii &r)const{ return w < r.w; }
};
class ii {
	public: int u, v;
	ii(int _u, int _v) { u = _u, v = _v; }
};
int N, M, p[MXN], pa[18][MXN], lvl[MXN], me[18][MXN], mn=2e9;
vector<iii> ed, del;
vector<ii> v[MXN];
int idx(int x, int y){ return (x * (N + 1)) + y + 1; }
int fd(int u){
	if(p[u] == u) return u;
	return p[u] = fd(p[u]);
}
void plca(int u, int p){
	for(int i = 1; i <= 17; i++){
		pa[i][u] = pa[i-1][pa[i-1][u]];
		me[i][u] = max(me[i-1][pa[i-1][u]], me[i-1][u]);
	}
	for(ii i: v[u]) if(i.u != p){ 
		lvl[i.u] = lvl[u] + 1;
		pa[0][i.u] = u;
		me[0][i.u] = i.v;
		plca(i.u, u);
	}
}
int lca(int u, int v){
	int mx=0;
	if(lvl[u] < lvl[v]) swap(u,v);
	for(int i = 17; i >= 0; i--) if(lvl[pa[i][u]] >= lvl[v]) mx = max(mx, me[i][u]), u = pa[i][u];
	if(u == v) return mx;
	for(int i = 17; i >= 0; i--) if(pa[i][u] != pa[i][v]) mx = max(mx, max(me[i][u], me[i][v])), u = pa[i][u], v = pa[i][v];
	return max(mx, max(me[0][u], me[0][v]));
}
int main(){
	scanf("%d %d", &N, &M);
	for(int i = 0, u; i < N; i++){
		for(int j = 0; j < M-1; j++) {
			scanf("%d", &u);
			ed.emplace_back(idx(i, j), idx(i, j + 1), u); 
		}
		if(i + 1 < N) for(int j = 0; j < M; j++){
			scanf("%d", &u);
			ed.emplace_back(idx(i, j), idx(i + 1, j), u);
		}
	}
	iota(p, p + MXN, 0);
	sort(ed.begin(), ed.end());
	for(auto i: ed) {
		int a = fd(i.u), b = fd(i.v);
		if(a == b) del.emplace_back(i); 
		else {
			p[a] = b;	
			v[i.u].emplace_back(i.v,i.w);
			v[i.v].emplace_back(i.u,i.w);
		}
	}
	plca(1, 0);
	for(auto i: del) mn = min(mn, i.w - lca(i.u, i.v));
	printf("%d",mn);
}
