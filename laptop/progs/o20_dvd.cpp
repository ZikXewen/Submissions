#include <bits/stdc++.h>
#define ii pair<int, int>
#define x first
#define y second
using namespace std;
const int X = 1e5 + 5;
int N, M, ar[X];
ii st[X << 2];
void bd(int l = 1, int r = N, int id = 1){
	if(l == r) { st[id] = ii(ar[l], ar[l]); return; }
	int m = (l + r) >> 1;
	bd(l, m, id << 1);
	bd(m + 1, r, id << 1 | 1);
	st[id] = ii(min(st[id << 1].x, st[id << 1 | 1].x), max(st[id << 1].y, st[id << 1 | 1].y));
}
void ud(int at, int va, int l = 1, int r = N, int id = 1){
	if(l == r) { st[id] = ii(va, va); return; }
	int m = (l + r) >> 1;
	if(at <= m) ud(at, va, l, m, id << 1);
	else ud(at, va, m + 1, r, id << 1 | 1);
	st[id] = ii(min(st[id << 1].x, st[id << 1 | 1].x), max(st[id << 1].y, st[id << 1 | 1].y));
}
ii qu(int al, int ar, int l = 1, int r = N, int id = 1){
	if(l > ar || r < al) return ii(2e9, 0);
	if(l >= al && r <= ar) return st[id];
	int m = (l + r) >> 1;
	ii ll = qu(al, ar, l, m, id << 1), rr = qu(al, ar, m + 1, r, id << 1 | 1);
	return ii(min(ll.x, rr.x), max(ll.y, rr.y));
}
int main(){
	scanf("%d %d", &N, &M);
	iota(ar, ar + N + 1, 0);
	bd();
	for(int u, v, w; M; M--) {
		scanf("%d %d %d", &w, &u, &v); u++, v++;
		if(w) {
			ii te = qu(u, v);
			if(te.x == u && te.y == v) printf("YES\n");
			else printf("NO\n");
		} else ud(u, ar[v]), ud(v, ar[u]), swap(ar[u], ar[v]);
	}
}
