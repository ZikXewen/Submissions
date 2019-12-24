#include <bits/stdc++.h>
#define lint long long
using namespace std;
const int X = 2e5 + 5;
int N, M;
lint st[2][X << 2], uu, vv, mx;
void bd(int l = 1, int r = N, int id = 1){
	if(l == r) {st[0][id] = l; st[1][id] = -l; return;}
	int m = (l + r) >> 1;
	bd(l, m, id << 1); bd(m + 1, r, id << 1 | 1);
	st[0][id] = max(st[0][id << 1], st[0][id << 1 | 1]);
	st[1][id] = max(st[1][id << 1], st[1][id << 1 | 1]);
}
void ud(int po, lint va, int l = 1, int r = N, int id = 1){
	if(l == r){if(st[0][id] < va + po) st[0][id] = va + po, st[1][id] = va - po; return;}
	int m = (l + r) >> 1;
	if(po <= m) ud(po, va, l, m, id << 1);
	else ud(po, va, m + 1, r, id << 1 | 1);
	st[0][id] = max(st[0][id << 1], st[0][id << 1 | 1]);
	st[1][id] = max(st[1][id << 1], st[1][id << 1 | 1]);
}
lint qu(int ty, int al, int ar, int l = 1, int r = N, int id = 1){
	if(al > r || ar < l) return -1e17;
	if(al <= l && ar >= r) return st[ty][id];
	int m = (l + r) >> 1;
	return max(qu(ty, al, ar, l, m, id << 1), qu(ty, al, ar, m + 1, r, id << 1 | 1));
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M; bd();
	for(int i = 0, u, v, w; i < M; ++i){
		cin >> u >> v >> w;
		vv = max(qu(0, 1, u) - u, qu(1, u, N) + u) + w;
		uu = max(qu(0, 1, v) - v, qu(1, v, N) + v) + w;
		mx = max({mx, uu, vv}); cout << mx << '\n';
		ud(v, vv), ud(u, uu);
	}
}
