#include <bits/stdc++.h>
using namespace std;
const int MD = 1e9 + 7;
const int X = 1e5 + 5;
struct one{
	char id; int prio, sz, ct[10]; bool mrk;
	one *l, *r;
	one(char u){id = u; prio = rand(); sz = 1; l = r = 0; mrk = 0; memset(ct, 0, sizeof ct); ct[u - 'a'] = 1;}
} *tr;
int N, M; string str;
int fact[X] = {1};
int _sz(one *u){return u? u -> sz : 0;}
int _ct(one *u, const int &k){return u? u -> ct[k] : 0;}
void ud(one *&u){
	if(!u) return;
	u -> sz = _sz(u -> l) + _sz(u -> r) + 1;
	for(int i = 0; i < 10; ++i) u -> ct[i] = _ct(u -> l, i) + _ct(u -> r, i);
	++(u -> ct[(u -> id) - 'a']);
}
void pus(one *&u){
	if(!u || !(u -> mrk)) return;
	u -> mrk = 0;
	swap(u -> l, u -> r);
	if(u -> l) u -> l -> mrk ^= 1;
	if(u -> r) u -> r -> mrk ^= 1;
}
void spl(one *u, one *&l, one *&r, int va){
	if(!u) {l = r = 0; return;}
	pus(u);
	if(_sz(u -> l) < va) spl(u -> r, u -> r, r, va - _sz(u -> l) - 1), l = u;
	else spl(u -> l, l, u -> l, va), r = u;
	ud(u);
}
void mrg(one *l, one *r, one *&u){
	pus(l), pus(r);
	if(!l || !r) {u = (l? l : r); return;}
	if(l -> prio < r -> prio) mrg(l -> r, r, l -> r), u = l;
	else mrg(l, r -> l, r -> l), u = r;
	ud(u);
}
void init(string str){
	for(char i: str){
		one *nw = new one(i);
		mrg(tr, nw, tr);
	}
	for(int i = 1; i < X; ++i) fact[i] = ((long long)fact[i - 1] * i) % MD;
}
void rev(int u, int v){
	one *l, *r;
	spl(tr, tr, r, v), spl(tr, l, tr, u - 1);
	if(tr) tr -> mrk ^= 1;
	mrg(l, tr, tr), mrg(tr, r, tr);
}
int div(int po){
	long long temp[31] = {po}, ret = 1;
	for(int i = 1; i <= 30; ++i) temp[i] = (temp[i - 1] * temp[i - 1]) % MD;
	for(int i = 30; i >= 0; --i) if((1 << i) & (MD - 2)) ret = (ret * temp[i]) % MD;
	return ret;
}
int calc(one *u){
	if(!u) return 0;
	long long ret = fact[(u -> sz) >> 1]; int od = 0;
	for(int i = 0; i < 10; ++i){
		if(u -> ct[i] & 1) ++od;
		ret = (ret * div(fact[(u -> ct[i]) >> 1])) % MD;
	}
	return od > 1? 0 : ret;
}
int que(int u, int v){
	one *l, *r;
	spl(tr, tr, r, v), spl(tr, l, tr, u - 1);
	int ret = calc(tr);
	mrg(l, tr, tr), mrg(tr, r, tr);
	return ret;
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	srand(time(0)); 
	cin >> N >> M >> str;
	init(str);
	for(int i = 0, u, v, w; i < M; ++i){
		cin >> u >> v >> w;
		if(u == 1) rev(v, w);
		else cout << que(v, w) << '\n';
	}
}