#include <bits/stdc++.h>
using namespace std;
const int X = 1e5 + 5;
struct node{
	int sz, prio; char va; bool mk;
	node *l, *r;
	node(char _va) : sz(1), prio(rand()), va(_va), mk(0), l(0), r(0) {}
} *tr;
int _sz(node *u){return u? u -> sz : 0;}
int _mk(node *u){return u? u -> mk : 0;}
void push(node *&u){
	if(!_mk(u)) return;
	u -> mk = 0;
	swap(u -> l, u -> r);
	if(u -> l) u -> l -> mk ^= 1;
	if(u -> r) u -> r -> mk ^= 1;
}
void ud(node *&u){
	if(!u) return;
	u -> sz = _sz(u -> l) + _sz(u -> r) + 1;
}
void spl(node *u, node *&l, node *&r, int va){
	push(u);
	if(!u) {l = r = 0; return;}
	if(_sz(u -> l) < va) spl(u -> r, u -> r, r, va - _sz(u -> l) - 1), l = u;
	else spl(u -> l, l, u -> l, va), r = u;
	ud(l); ud(r);
}
void mrg(node *l, node *r, node *&u){
	push(l), push(r);
	if(!l or !r) {u = (l? l : r); return;}
	if(l -> prio < r -> prio) mrg(l, r -> l, r -> l), u = r;
	else mrg(l -> r, r, l -> r), u = l;
	ud(u);
}
void ins(node *&u, node *&nw, int po){
	node *l;
	spl(u, l, u, po);
	mrg(l, nw, l); mrg(l, u, u);
}
void mktr(node *&u, string &str){
	for(int i = str.size(); i; --i) {
		node *nw = new node(str[i - 1]); 
		ins(u, nw, 0);
	}
}
void rev(node *&u, int bg, int ed){
	node *l, *r;
	spl(u, u, r, ed);
	spl(u, l, u, bg - 1);
	if(u) u -> mk ^= 1; 
	mrg(l, u, u);
	mrg(u, r, u);
}
void prt(node *&u){
	if(!u) return;
	push(u);
	prt(u -> l);
	cout << u -> va;
	prt(u -> r);
}
string in;
int Q;
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	srand(time(0));
	cin >> in >> Q;
	mktr(tr, in);
	while(Q--){
		int a, b; char c; string s;
		cin >> c >> a;
		if(c == 'I'){
			cin >> s;
			node *nw = 0; mktr(nw, s);
			ins(tr, nw, a);
		} else {
			cin >> b;
			rev(tr, a, b);
		}	
	} 
	prt(tr);
}