#include <bits/stdc++.h>
using namespace std;
const int X = (1 << 20) - 1;
struct one{
	int va;
	one *l, *r;
	one() = default;
} *tr[X];
int M, ls;
void bd(one *tr, int l = 0, int r = X){
	if(l == r) return;
	int m = (l + r) >> 1;
	bd(tr -> l = new one(), l, m); bd(tr -> r = new one(), m + 1, r);
}
void add(int po, one *pr, one *cr, int l = 0, int r = X){
	if(l == r) return (cr -> va = (pr -> va) + 1), void();
	int m = (l + r) >> 1;
	if(po <= m) add(po, pr -> l, cr -> l = new one(), l, m), cr -> r = pr -> r;
	else add(po, pr -> r, cr -> r = new one(), m + 1, r), cr -> l = pr -> l;
	cr -> va = (cr -> l -> va) + (cr -> r -> va);
}
int que1(one *u, one *v, int po, int l = 0, int r = X, int d = 19){
	if(l == r) return l;
	int m = (l + r) >> 1;
	if((1 << d) & po){
		if((v -> l -> va) - (u -> l -> va)) return que1(u -> l, v -> l, po, l, m, d - 1);
		else return que1(u -> r, v -> r, po, m + 1, r, d - 1);
	} else {
		if((v -> r -> va) - (u -> r -> va)) return que1(u -> r, v -> r, po, m + 1, r, d - 1);
		else return que1(u -> l, v -> l, po, l, m, d - 1);
	}
}
int que2(one *u, one *v, int po, int l = 0, int r = X){
	if(po < l) return 0;
	if(r <= po) return (v -> va) - (u -> va);
	int m = (l + r) >> 1;
	return que2(u -> l, v -> l, po, l, m) + que2(u -> r, v -> r, po, m + 1, r);
}
int que3(one *u, one *v, int po, int l = 0, int r = X){
	if(l == r) return l;
	int m = (l + r) >> 1;
	if(po <= (v -> l -> va) - (u -> l -> va)) return que3(u -> l, v -> l, po, l, m);
	else return que3(u -> r, v -> r, po - ((v -> l -> va) - (u -> l -> va)), m + 1, r);
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	bd(tr[0] = new one());
	cin >> M; while(M--){
		int u, v, w, z;
		cin >> u >> v;
		if(u == 0) add(v, tr[ls++], tr[ls + 1] = new one());
		else if(u == 1) cin >> w >> z, cout << que1(tr[v - 1], tr[w], z) << '\n';
		else if(u == 2) ls -= v;
		else if(u == 3) cin >> w >> z, cout << que2(tr[v - 1], tr[w], z) << '\n';
		else cin >> w >> z, cout << que3(tr[v - 1], tr[w], z) << '\n';
	}
}