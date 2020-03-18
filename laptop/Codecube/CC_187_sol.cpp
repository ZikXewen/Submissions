#include <bits/stdc++.h>
using namespace std;
struct one{
	int sz, prio; char va; bool mrk;
	one *l, *r;
	one(char _va){va = _va, sz = 1, prio = rand(); l = r = 0; mrk = 0;}
} *tr;
int _sz(one *u){return u? u -> sz : 0;}
bool _mrk(one *u){return u? u -> mrk : 0;}
string inp; int N, k, p; char ch;
void pus(one *&u){
	if(!_mrk(u)) return;
	u -> mrk = 0;
	swap(u -> l, u -> r);
	if(u -> l) u -> l -> mrk ^= 1;
	if(u -> r) u -> r -> mrk ^= 1;
}
void ud(one *&u){
	if(!u) return;
	u -> sz = _sz(u -> l) + _sz(u -> r) + 1;
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
	if(l -> prio < r -> prio) mrg(l, r -> l, r -> l), u = r;
	else mrg(l -> r, r, l -> r), u = l;
	ud(u);
}
void ins(one *&u, char va, int po){
	one *r, *nw = new one(va);
	spl(u, u, r, po); mrg(u, nw, u); mrg(u, r, u);
}
void mktr(one *&u, string &str){
	ins(u, str.back(), 0);
	for(int i = str.size() - 2; i >= 0; --i) ins(u, str[i], 0);
}
void _ins(int po, string &va){
	one *r, *nw; mktr(nw, va);
	spl(tr, tr, r, po); mrg(tr, nw, tr); mrg(tr, r, tr);
}
void prt(one *u = tr){
	if(!u) return;
	pus(u); prt(u -> l); cout << u -> va; prt(u -> r);
}
void rev(int k, int p){
	one *l, *r;
	spl(tr, tr, r, p); spl(tr, l, tr, k - 1);
	if(tr) tr -> mrk ^= 1;
	mrg(l, tr, tr); mrg(tr, r, tr);
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	srand(time(0)); cin >> inp >> N;
	mktr(tr, inp);
	for(int i = 0; i < N; ++i){
		cin >> ch;
		if(ch == 'I') cin >> k >> inp, _ins(k, inp);
		else cin >> k >> p, rev(k, p);
	}
	prt();
}