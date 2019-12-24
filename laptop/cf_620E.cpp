#include <bits/stdc++.h>
#define lint long long 
using namespace std;
const int X = 4e5 + 5;
int N, M, ar[X], in[X], ot[X], ct, lz[X << 3], pat[X << 1];
lint st[X << 3];
vector<int> g[X];
void eul(int u, int p){
	in[u] = ++ct; pat[ct] = u;
	for(int v:g[u]) if(v != p) eul(v, u);
	ot[u] = ++ct; pat[ct] = u;
}
void chn(int id, int va){
	st[id] = 1ll << va; 
	if(id <= N << 1) lz[id << 1] = lz[id << 1 | 1] = va;
}
void bd(int l = 1, int r = N, int id = 1){
	if(l == r) {st[id] = 1ll << ar[pat[l]]; return;}
	int m = (l + r) >> 1;
	bd(l, m, id << 1), bd(m + 1, r, id << 1 | 1);
	st[id] = st[id << 1] | st[id << 1 | 1];
}
void ud(int al, int ar, int va, int l = 1, int r = N, int id = 1){
	if(lz[id]) chn(id, lz[id]), lz[id] = 0;
	if(al > r || ar < l) return;
	if(al <= l && ar >= r) {chn(id, va); return;}
	int m = (l + r) >> 1;
	ud(al, ar, va, l, m, id << 1), ud(al, ar, va, m + 1, r, id << 1 | 1);
	st[id] = st[id << 1] | st[id << 1 | 1];
}
long long qu(int al, int ar, int l = 1, int r = N, int id = 1){
	if(lz[id]) chn(id, lz[id]), lz[id] = 0;
	if(al > r || ar < l) return 0ll;
	if(al <= l && ar >= r) return st[id];
	int m = (l + r) >> 1;
	return qu(al, ar, l, m, id << 1) | qu(al, ar, m + 1, r, id << 1 | 1);
}
int main(){
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; i++) scanf("%d", &ar[i]);
	for(int i = 1, u, v; i < N; i++) scanf("%d %d",&u, &v), g[u].emplace_back(v), g[v].emplace_back(u);
	eul(1, 0); N <<= 1; bd();
	while(M--){
		int t, u, v;
		scanf("%d", &t);
		if(t == 1){
			scanf("%d %d", &u, &v);
			ud(in[u], ot[u], v);
		} else {
			scanf("%d", &u);
			printf("%d\n", __builtin_popcountll(qu(in[u], ot[u])));
		}
	}
}
