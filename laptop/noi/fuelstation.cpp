#include <bits/stdc++.h>
using namespace std;
const int X = 3e5 + 5;
struct one{
	int x, a, b;
	bool operator<(const one &r){return b < r.b;}
} ar[X];
int N, D, sz, mp[X];
long long st[X << 3], lz[X << 3];
void ud(int po, int va, int l = 0, int r = sz - 1, int id = 1){
	if(lz[id]){
		st[id] += lz[id]; 
		if(l < r) lz[id << 1] += lz[id], lz[id << 1 | 1] += lz[id]; 
		lz[id] = 0;
	}
	if(l == r) {st[id] += va; return;}
	int m = l + r >> 1;
	if(po <= m) ud(po, va, l, m, id << 1);
	else ud(po, va, m + 1, r, id << 1 | 1);
	st[id] = min(st[id << 1], st[id << 1 | 1]);
}
void rud(int al, int ar, int va, int l = 0, int r = sz - 1, int id = 1){
	//if(al > ar) return;
	if(lz[id]){
		st[id] += lz[id]; 
		if(l < r) lz[id << 1] += lz[id], lz[id << 1 | 1] += lz[id]; 
		lz[id] = 0;
	}
	if(ar < l || al > r) return;
	
	if(al <= l && ar >= r){
		st[id] += va;
		if(l < r) lz[id << 1] += va, lz[id << 1 | 1] += va;
		return;
	}
	int m = l + r >> 1;
	rud(al, ar, va, l, m, id << 1);
	rud(al, ar, va, m + 1, r, id << 1 | 1);
	st[id] = min(st[id << 1], st[id << 1 | 1]);
}
/*void prt(int l = 0, int r = sz - 1, int id = 1){
	if(lz[id]){
		st[id] += lz[id]; 
		if(l < r) lz[id << 1] += lz[id], lz[id << 1 | 1] += lz[id]; 
		lz[id] = 0;
	}
	if(l == r) {cout << st[id] << ' '; return;}
	int m = l + r >> 1;
	prt(l, m, id << 1), prt(m + 1, r, id << 1 | 1);
}*/
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> D; // Stations, Dist
	for(int i = 0; i < N; ++i) cin >> ar[i].x >> ar[i].a >> ar[i].b, mp[i + 1] = ar[i].x; // Dist, Lim Fuel, Lim Start
	mp[N + 1] = D;
	sort(mp, mp + N + 2); sz = unique(mp, mp + N + 2) - mp;
	for(int i = 0; i < sz; ++i) ud(i, -mp[i]);
	for(int i = 0; i < N; ++i) rud(ar[i].x = lower_bound(mp, mp + sz, ar[i].x) - mp + 1, sz - 1, ar[i].a);
	//prt();
	sort(ar, ar + N);
	for(int i = 0; i < N; ++i){
		//assert(!lz[1]);
		if(-st[1] <= ar[i].b) {cout << -st[1]; return 0;}
		rud(ar[i].x, sz - 1, -ar[i].a); // more starting fuel, less stations
	}
	cout << D;
}