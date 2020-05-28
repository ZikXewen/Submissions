// TREAP + CONVEX HULL
#include <bits/stdc++.h>
using namespace std;
struct ii{
	long x, y;
	ii(long u, long v) : x(u), y(v) {};
	//bool operator<(ii v){return x < v.x || (x == v.x && y < v.y);}
};
struct one{
	int sz, prio;
	ii va;
	double sm;
	one *l, *r;
	one(int u, int v) : va(u, v), sz(1), sm(0), l(0), r(0), prio(rand()) {};
} *tr;
int _sz(one *u){return u? u -> sz : 0;}
//ii _va(one *u){return u? u -> va : }
double _sm(one *u){return u? u -> sm : 0;}
void ud(one *u){
	if(!u) return;
	u -> sz = _sz(u -> l) + _sz(u -> r) + 1;
	u -> sm = _sm(u -> l) + _sm(u -> r) /*+ u -> va*/;
}
ii _vat(int po, one *now = tr){ // value of now(tr) @ po
	if(!now) return ii(-1, -1);
	if(_sz(now -> l) == po) return now -> va;
	if(_sz(now -> l) > po) return _vat(po, now -> l);
	return _vat(po - _sz(now -> l) - 1, now -> r);
}
void mrg(one *l, one *r, one *&u){
	if(!l || !r) {u = (l? l : r); return;} 
	if(l -> prio < r -> prio) mrg(l -> r, r, l -> r), u = l;
	else mrg(l, r -> l, r -> l), u = r;
	ud(u);
}
void spl(one *u, one *&l, one *&r, int va){
	if(!u) {l = r = NULL; return;}
	if(_sz(u -> l) <= va) spl(u -> r, u -> r, r, va - _sz(u -> l) - 1), l = u;
	else spl(u -> l, l, u -> l, va), r = u;
	ud(u);
}
void prnt(one *nw = tr){
	if(!nw) return;
	prnt(nw -> l);
	cout << nw -> va.x << ' ' << nw -> va.y << '\n';
	//cout << nw -> sz;
	prnt(nw -> r);
}
double sm;
int N;
long ori(ii O, ii A, ii B){return 1ll * (A.x - O.x) * (B.y - O.y) - 1ll * (A.y - O.y) * (B.x - O.x);}
void ins(long x, long y){
	// Base cases
	if(_sz(tr) < 2) {mrg(tr, new one(x, y), tr); return;}
	if(_sz(tr) == 2){
		if(ori(_vat(0), _vat(1), ii(x, y)) <= 0) {mrg(tr, new one(x, y), tr); return;}
		one *r; spl(tr, tr, r, 0); mrg(tr, new one(x, y), tr); mrg(tr, r, tr); return;
	}

	ii nw(x, y), ftr = _vat(0);

	// Special Case, Need new start
	if(ori(ftr, _vat(_sz(tr) - 1), nw) <= 0 && ori(ftr, _vat(1), nw) >= 0){ 
		int l = 1, r = _sz(tr) - 1;
		while(l < r){
			int m = (l + r + 1) >> 1;
			if(ori(nw, ftr, _vat(m)) >= 0) l = m; // Last right
			else r = m - 1;
		}
		one *lt;
		spl(tr, lt, tr, l - 1); mrg(tr, lt, tr);
		ftr = _vat(0);
	}

	// Find Mid
	int ml = 1, mr = _sz(tr) - 1;
	if(ori(ftr, _vat(1), nw) > 0) ml = 0;
	else{
		while(ml < mr){
			int m = (ml + mr + 1) >> 1;
			if(ori(ftr, _vat(m), nw) <= 0) ml = m; // Last left
			else mr = m - 1;
		}
		if(ori(_vat(ml), _vat((ml + 1) % _sz(tr)), nw) <= 0) return; // Inside the shape
	}

	// Find Left to delete
	int ll = 0, lr = ml;
	while(ll < lr){
		int m = (ll + lr) >> 1;
		if(ori(_vat(m), _vat((m + 1) % _sz(tr)), nw) < 0) ll = m + 1; // First right
		else lr = m;
	}

	// Find Right to delete
	int rl = ml + 1, rr = _sz(tr) - 1;
	while(rl < rr){
		int m = (rl + rr) >> 1;
		if(ori(_vat((m + 1) % _sz(tr)), _vat(m), nw) < 0) rl = m + 1; // First right
		else rr = m;
	}

	prnt(); cout << '\n';

	// Cuts & Insert
	one *rt, *lt, *nt = new one(x, y);
	spl(tr, tr, rt, rl - 1); spl(tr, lt, tr, ll);
	mrg(lt, nt, tr), mrg(tr, rt, tr);

	cout << ":" << ml << '\n'; prnt(); cout << '\n';
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0), srand(time(0));
	cin >> N;
	for(int i = 0, x, y; i < N; ++i){
		cin >> x >> y;
		ins(x, y);
		//cout << tr -> sz << '\n';
	}
}