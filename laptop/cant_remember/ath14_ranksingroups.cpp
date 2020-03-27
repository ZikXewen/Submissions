#include <bits/stdc++.h>
using namespace std;
const int X = 1e5 + 5;
struct one{
	int va, prio, sz;
	one *l, *r;
	one(int u){va = u; prio = rand(); sz = 1; l = r = 0;}
} *tr[X];
int _sz(one *u){return u? u -> sz : 0;}
int pa[X];
void ud(one *&u){
	if(!u) return;
	u -> sz = _sz(u -> l) + _sz(u -> r) + 1;
}
void spl(one *u, one *&l, one *&r, int va){
	if(!u) {l = r = 0; return;}
	if(u -> va < va) spl(u -> r, u -> r, r, va), l = u;
	else spl(u -> l, l, u -> l, va), r = u;
	ud(u);
}
void mrg(one *l, one *r, one *&u){
	if(!l || !r) {u = l? l : r; return;}
	if(l -> prio < r -> prio) mrg(l, r -> l, r -> l), u = r;
	else mrg(l -> r, r, l -> r), u = l;
	ud(u);
}
void ins(one *& u, int va){
	one *r, *nw = new one(va);
	spl(u, u, r, va); mrg(u, nw, u); mrg(u, r, u);
}
void inor(one *u, int v){
	if(!u) return;
	inor(u -> l, v); ins(tr[v], u -> va); inor(u -> r, v);
}
void bin(int u, int v){
	pa[v] = u;
	if(_sz(tr[u]) < _sz(tr[v])) swap(tr[u], tr[v]);
	inor(tr[v], u); tr[v] = 0;
}
int fd(int u){return pa[u] == u? u : pa[u] = fd(pa[u]);}
int que(int u){
	int pu = fd(u);
	one *r; spl(tr[pu], tr[pu], r, u);
	int ret = _sz(r);
	mrg(tr[pu], r, tr[pu]);
	return ret;
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0), srand(time(0));
	int T, N, M;
	cin >> T; while(T--){
		cin >> N >> M;
		for(int i = 0; i <= N; ++i) pa[i] = i, tr[i] = new one(i);
		for(int i = 0, u, v, w; i < M; ++i){
			cin >> u >> v;
			if(u == 1) cin >> w, bin(v, w);
			else cout << que(v) << '\n';
		}
	}
}