#include <bits/stdc++.h>
#define lint long long 
#define ii pair<lint, int>
#define x first
#define y second
using namespace std;
const int X = 1e5 + 5, Y = 1e7 + 5;
ii ar[X], te; lint co[Y];
int N, M, hd[X], ll[Y], rr[Y], sz[Y], id;
void ud(int ol, int nw, int po, int va, int l = 1, int r = N){
	if(l == r) {co[nw] = va, sz[nw]++; return;}
	int m = (l + r) >> 1;
	if(po <= m) rr[nw] = rr[ol], ud(ll[ol], ll[nw] = ++id, po, va, l, m);
	else ll[nw] = ll[ol], ud(rr[ol], rr[nw] = ++id, po, va, m + 1, r);
	co[nw] = co[ll[nw]] + co[rr[nw]];
	sz[nw] = sz[ll[nw]] + sz[rr[nw]];
}
ii qu(int ve, int al, int ar, int l = 1, int r = N){
	if(al > r || ar < l) return ii(0ll, 0);
	if(al <= l && ar >= r) return ii(co[ve], sz[ve]);
	int m = (l + r) >> 1;
	ii tel = qu(ll[ve], al, ar, l, m), ter = qu(rr[ve], al, ar, m + 1, r);
	return ii(tel.x + ter.x, tel.y + ter.y);
}
int main(){
	freopen("in", "r", stdin); freopen("out2", "w", stdout);
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++) scanf("%d", &ar[i].first), ar[i].second = i + 1;
	sort(ar, ar + N, greater<ii>());
	for(int i = 0; i < N; i++) hd[i + 1] = ++id, ud(hd[i], hd[i + 1], ar[i].y, ar[i].x);
	for(int i = 0, u, v; i < M; i++) {
		double w; scanf("%d %d %lf", &u, &v, &w);
		int l = 1, r = N, an = 0;
		while(l < r){
			int m = (l + r + 1) >> 1;
			te = qu(hd[m], u, v);
			if((double)te.x / te.y < w) r = m - 1;
			else l = m;
		}
		printf("%d\n", te.y? v - u + 1 - te.y : -1);
	}
}
