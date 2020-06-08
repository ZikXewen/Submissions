// TREAP + CONVEX HULL
#include <bits/stdc++.h>
#define long long long
using namespace std;
struct ii{
	long x, y;
	ii(long u, long v) : x(u), y(v) {};
};
const ii INF(1e6 + 1, 1e6 + 1);
bool operator==(const ii &u, const ii &v){return u.x == v.x;}
double dis(ii u, ii v){return (u == INF)? 0 : sqrt((u.x - v.x) * (u.x - v.x) + (u.y - v.y) * (u.y - v.y));}

struct one{
	int sz, prio;
	ii va;
	double sm;
	one *l, *r, *p, *ll, *rr;
	one(int u, int v) : va(u, v), sz(1), sm(0), l(0), r(0), p(0), rr(this), ll(this), prio(rand()) {};
} *tr;
int _sz(one *u){return u? u -> sz : 0;}
ii _va(one *u){return u? u -> va : INF;}
double _sm(one *u){return u? u -> sm : 0;}
void ud(one *u){
	if(!u) return;
	u -> ll = u -> l? u -> l -> ll : u;
	u -> rr = u -> r? u -> r -> rr : u;
	u -> sz = _sz(u -> l) + _sz(u -> r) + 1;
	u -> sm = _sm(u -> l) + _sm(u -> r) + dis((u -> l)? _va(u -> l -> rr) : INF, u -> va) + dis((u -> r)? _va(u -> r -> ll) : INF, u -> va);
}
one* _vat(int po, one *now = tr){ // value of now(tr) @ po
	if(!now) return nullptr;
	if(_sz(now -> l) == po) return now;
	if(_sz(now -> l) > po) return _vat(po, now -> l);
	return _vat(po - _sz(now -> l) - 1, now -> r);
}
void mrg(one *l, one *r, one *&u){
	if(!l or !r) {u = l? l : r;  return;} 
	if(l -> prio < r -> prio) mrg(l -> r, r, l -> r), u = l;
	else mrg(l, r -> l, r -> l), u = r;
	ud(u);
}
void spl(one *u, one *&l, one *&r, int va){
	if(!u) {l = r = NULL; return;}
	if(_sz(u -> l) <= va) spl(u -> r, u -> r, r, va - _sz(u -> l) - 1), l = u;
	else spl(u -> l, l, u -> l, va), r = u;
	ud(u); ud(l); ud(r);
}

double sm;
int N;
long ori(ii O, ii A, ii B){return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);}
long ori(one *O, one* A, one *B){return ori(O -> va, A -> va, B -> va);}
void ins(long x, long y){

    one *nw = new one(x, y);

	// Base cases
	if(_sz(tr) < 2) {mrg(tr, nw, tr); return;}
	if(_sz(tr) == 2){
		one *v0 = _vat(0), *v1 = _vat(1);
		if(ori(v0, v1, nw) == 0) {
			if(dis(_va(v0), _va(v1)) + dis(_va(v1), _va(nw)) == dis(_va(v0), _va(nw))) mrg(v0, nw, tr);
			else if(dis(_va(v0), _va(v1)) + dis(_va(v0), _va(nw)) == dis(_va(v1), _va(nw))) mrg(v1, nw, tr);
			return;
		}
		if(ori(v0, v1, nw) < 0) {mrg(tr, nw, tr); return;}
		mrg(v0, nw, tr); mrg(tr, v1, tr); return;
	}

	one *ftr = _vat(0);

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
	int ml = 0, mr = _sz(tr) - 1;
	if(ori(ftr, _vat(1), nw) > 0) ml = 0;
	else{
		while(ml < mr){
			int m = (ml + mr + 1) >> 1;
			if(ori(ftr, _vat(m), nw) <= 0) ml = m; // Last left
			else mr = m - 1;
		}
		if(ori(_vat(ml), _vat((ml + 1) % _sz(tr)), nw) < 0) return; // Inside the shape
	}
    
	// Find Left to delete
	int ll = 0, lr = ml;
	while(ll < lr){
		int m = (ll + lr) >> 1;
		if(ori(_vat(m), _vat((m + 1) % _sz(tr)), nw) < 0) ll = m + 1; // First right/equ
		else lr = m;
	}

	// Find Right to delete
	int rl = ml + 1, rr = _sz(tr) - 1;
	while(rl < rr){
		int m = (rl + rr) >> 1;
		if(ori(_vat((m + 1) % _sz(tr)), _vat(m), nw) <= 0) rl = m + 1; // first right only!
		else rr = m;
	}

	// Cuts & Insert
	one *rt, *lt, *nt = new one(x, y);
	spl(tr, tr, rt, rl - 1); spl(tr, lt, tr, ll);
	mrg(lt, nt, tr), mrg(tr, rt, tr);
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0), srand(time(0));
	cout << fixed << setprecision(6);
	cin >> N;
	for(int i = 0, x, y; i < N; ++i){
		cin >> x >> y;
		ins(x, y);
		cout << _sm(tr) + dis(_va(tr -> ll), _va(tr -> rr)) << "\n";
	}
}