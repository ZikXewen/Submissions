#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 5;
struct one{
	int va, sz, mx, mn, mdiff, prio;
	one *l, *r;
	one(int val){sz = 1, va= val, mx = val, mn = val, mdiff = INF, prio = rand(), l = NULL; r = NULL;}
} *tr;
int _sz(one *u){return u? u -> sz : 0;}
int _mx(one *u){return u? u -> mx : -INF;}
int _mn(one *u){return u? u -> mn : INF;}
int _mdiff(one *u){return u? u -> mdiff : INF;}
int N, k, p; char in;
void ud(one *u){
	if(!u) return;
	u -> sz = _sz(u -> l) + _sz(u -> r) + 1;
	u -> mx = max(max(_mx(u -> l), _mx(u -> r)), u -> va);
	u -> mn = min(min(_mn(u -> l), _mn(u -> r)), u -> va);
	u -> mdiff = min(min(_mdiff(u -> l), _mdiff(u -> r)), min(_mn(u -> r) - u -> va, u -> va - _mx(u -> l)));
}
void spl(one *u, one *&l, one *&r, int va){
	if(!u) {l = r = NULL; return;}
	if(u -> va < va) spl(u -> r, u -> r, r, va), l = u;
	else spl(u -> l, l, u -> l, va), r = u;
	ud(u);
}
void mrg(one *l, one *r, one *&u){
	if(!l || !r) {u = (l? l : r); return;}
	if(l -> prio < r -> prio) mrg(l, r -> l, r -> l), u = r;
	else mrg(l -> r, r, l -> r), u = l;
	ud(u);
}
void spv(one *u, one *&l, one *&r, int va){
	if(!u) {l = r = NULL; return;}
	if(_sz(u -> l) < va) spv(u -> r, u -> r, r, va - _sz(u -> l) - 1), l = u; 
	else spv(u -> l, l, u -> l, va), r = u;
	ud(u);
}
void ins(int u){
	one *l, *r, *nw = new one(u);
	spl(tr, l, tr, u); spl(tr, tr, r, u + 1);
	mrg(l, nw, tr); mrg(tr, r, tr);
}
void del(int u){
	one *l, *r;
	spl(tr, l, tr, u); spl(tr, tr, r, u + 1);
	mrg(l, r, tr);
}
int gtn(int p, int q){
	one *l, *r;
	spv(tr, tr, r, q + 1); spv(tr, l, tr, p);
	int ret = _mdiff(tr);
	mrg(tr, r, tr); mrg(l, tr, tr);
	return ret;
}
int gtx(int p, int q){
	one *l, *r;
	spv(tr, tr, r, q + 1); spv(tr, l, tr, p);
	int ret = _mx(tr) - _mn(tr);
	mrg(tr, r, tr); mrg(l, tr, tr);
	return ret;
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	srand(time(0)); cin >> N;
	for(int i = 0; i < N; ++i){
		cin >> in;
		switch(in){
			case 'I': cin >> k; ins(k); break;
			case 'D': cin >> k; del(k); break;
			case 'N': cin >> k >> p; cout << ((k < p)? gtn(k, p) : -1) << '\n'; break;
			case 'X': cin >> k >> p; cout << ((k < p)? gtx(k, p) : -1) << '\n'; break;
		}
	}
}