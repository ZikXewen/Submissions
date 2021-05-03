#include <bits/stdc++.h>
#define int64 long long
using namespace std;
const int X = 2e5 + 5, TRSZ = 1e6 + 5;
const int64 NINF = -1e18;
struct pnt{
	int64 u, v;
	int64 operator()(int x){return u * x + v;}
	pnt(int64 _u, int64 _v) : u(_u), v(_v) {}
};
struct node{
	int lo, hi;
	pnt va;
	node *l, *r;
	node(int _lo, int _hi) : lo(_lo), hi(_hi), va(0, NINF), l(), r() {}
	void add(pnt u){
		int m = (lo + hi) >> 1;
		if(u(m) > va(m)) swap(u, va);
		if(lo == hi) return;
		if((u(lo) > va(lo)) == (u(m) > va(m))){
			if(!r) r = new node(m + 1, hi);
			r -> add(u);
		} else {
			if(!l) l = new node(lo, m);
			l -> add(u);
		}
	}
	int64 que(int u){
		node *nx = ((u <= (lo + hi) >> 1)? l : r);
		return max(va(u), (nx? nx -> que(u) : NINF));
	}
} *tr;
int N;
int64 ar[X], sm[X], mx = NINF, fsm;
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	tr = new node(-TRSZ, TRSZ);
	for(int i = 1; i <= N; ++i) cin >> ar[i], sm[i] = sm[i - 1] + ar[i], fsm += ar[i] * i;
	for(int i = 1; i <= N; ++i) mx = max(mx, sm[i - 1] - i * ar[i] + tr -> que(ar[i])), tr -> add(pnt(i, -sm[i - 1]));
	tr = new node(-TRSZ, TRSZ);
	for(int i = N; i; --i) mx = max(mx, sm[i] - ar[i] * i + tr -> que(ar[i])), tr -> add(pnt(i, -sm[i]));
	cout << fsm + max(mx, 0ll);
}