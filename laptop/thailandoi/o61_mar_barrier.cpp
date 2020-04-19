#include <bits/stdc++.h>
using namespace std;
struct ii{
	long x, y;
	ii(long u, long v) : x(u), y(v) {};
	//bool operator<(ii v){return x < v.x || (x == v.x && y < v.y);}
}
struct one{
	int sz;
	ii va;
	double sm;
	one *l, *r;
	one(int u, int v) : va(u, v), sz(1), sm(0), l(0), r(0) {};
	
} *tr;
int _sz(one *u){return u? u -> sz : 0;}
//ii _va(one *u){return u? u -> va : }
double _sm(one *u){return u? u -> sm : 0;}
ii _vat(int po, one *now = tr){ // value of now(tr) @ po
	if(!now) return ii(-1, -1);
	if(_sz(now -> l) == po) return now -> va;
	if(_sz(now -> l) < po) return _vat(po, now -> l)
	return _vat(po - _sz(now -> l) - 1, now -> r);
}
double sm;
int N;
long ori(ii O, ii A, ii B){return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);}
void ins(long x, long y){
	if(_sz(tr) < 2) {mrg(tr, new one(x, y), tr); return;}
	if(_sz(tr))

	int ml = 1, mr = _sz(tr) - 1; ii nw(x, y);
	one *ftr = _vat(0);
	while(ml < mr){
		int m = (ml + mr + 1) >> 1;
		if(ori(ftr, _vat(m), nw) <= 0) ml = m; // Last left
		else mr = m - 1;
	}
	if(ori(_vat(ml), _vat(ml + 1), nw) <= 0) return;

	int ll = 1, rr = ml;
	while(ll < rr){
		int m = (ll + rr) >> 1;
		if(ori(_vat(m), _vat(m + 1), nw) < 0) ll = m + 1; // First right
		else rr = m;
	}

	int rl = ml + 1, rr = ar.size() - 1;
	while(rl < rr){
		int m = (rl + rr) >> 1;
		if(ori(_vat(m + 1), _vat(m), nw) < 0) rl = m + 1; // First right
		else ar = m;
	}

	one *rt, *lt, *nt = new one(x, y);
	spl(tr, tr, rt, rl); spl(tr, lt, tr, ll);
	mrg(lt, nt, tr), mrg(tr, rt, tr);
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for(int i = 0, x, y; i < N; ++i){
		cin >> x >> y;
		ins(x, y);
		cout << tr -> sm << '\n';
	}
}