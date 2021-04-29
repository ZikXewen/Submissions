#include <bits/stdc++.h>
using namespace std;
struct one{
	int va, prio, sz;
	bool mrk;
	one *l, *r;
	one(int u){va = u, prio = rand(), sz = 1; mrk = 0; l = r = 0;}
} *tr;
int _sz(one *u){return u? u -> sz : 0;}
int N, M;
void pus(one *&u){
	if(!u || !(u -> mrk)) return;
	u -> mrk = 0;
	if(u -> l) u -> l -> mrk ^= 1;
	if(u -> r) u -> r -> mrk ^= 1;
	swap(u -> l, u -> r);
}
void ud(one *&u){
	if(!u) return;
	u -> sz = _sz(u -> l) + _sz(u -> r) + 1;
}
void spl(one *u, one *&l, one *&r, int va){
	pus(u);
	if(!u){l = r = 0; return;}
	if(_sz(u -> l) < va) spl(u -> r, u -> r, r, va - _sz(u -> l) - 1), l = u;
	else spl(u -> l, l, u -> l, va), r = u;
	ud(u);
}
void mrg(one *l, one *r, one *&u){
	pus(l), pus(r);
	if(!l || !r){u = l? l : r; return;}
	if(l -> prio < r -> prio) mrg(l -> r, r, l -> r), u = l;
	else mrg(l, r -> l, r -> l), u = r;
	ud(u);
}
void rev(one *&u){
	if(!u) return;
	u -> mrk ^= 1; pus(u);
}
void inor(one *&u){
	if(!u) return;
	pus(u); inor(u -> l);
	cout << u -> va << ' '; inor(u -> r);
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0), srand(time(0));
	cin >> N >> M;
	for(int i = N; i; --i) mrg(new one(i), tr, tr);
	for(int i = 0, u, v, w; i < M; ++i){
		cin >> u >> v >> w;
		one *a, *b, *c;
		spl(tr, a, tr, u);
		spl(tr, b, tr, v);
		mrg(a, tr, tr);
		spl(tr, c, tr, w);
		rev(b), mrg(b, tr, tr);
		mrg(c, tr, tr);
	}
	inor(tr);
}