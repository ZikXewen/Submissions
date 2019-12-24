#include<bits/stdc++.h>
using namespace std;
const int MXN = 10005;
int N, pa[MXN], de[MXN], e1[MXN], e2[MXN], cd[MXN], rt[MXN], sp[MXN], ps[MXN], id, st[MXN << 2], rv[MXN], cs[MXN];
// parents, depth, edges1, edges2, child, root, special, position, running index, segment tree, reverse id, cost to parent
vector<int> g[MXN],c[MXN];

void deb(){cout << 'o';}
void dfs(int u, int p){
	pa[u] = p;
	de[u] = de[p] + 1;
	cd[u] = 1;
	if(g[u].size() == 1 && p) return;
	sp[u] = (g[u][0] == p)? g[u][1] : g[u][0];
	for(int i = 0; i < g[u].size(); i++) if(g[u][i] != p){
		dfs(g[u][i], u);
		cd[u] += cd[g[u][i]];
		cs[g[u][i]] = c[u][i];
		if(cd[g[u][i]] > cd[sp[u]]) sp[u] = g[u][i];
	}
}
void hld(int u){
	ps[u] = ++id;
	rv[id] = u;
	if(sp[pa[u]] != u) rt[u] = u;
	else rt[u] = rt[pa[u]];
	if(g[u].size() == 1 && pa[u]) return;
	hld(sp[u]);
	for(int i : g[u]) if(i != pa[u] && i != sp[u]) hld(i);
}
void bld(int l, int r, int cr){
	if(l == r) {st[cr] = cs[rv[l]]; return;}
	int m = (l + r) >> 1;
	bld(l, m, cr << 1); bld(m + 1, r, (cr << 1) | 1);
	st[cr] = max(st[cr << 1], st[(cr << 1) | 1]);
}
void upd(int l, int r, int cr, int ud, int va){
	if(l == r) {st[cr] = va; return;}
	int m = (l + r) >> 1;
	if(ud <= m) upd(l, m, cr << 1, ud, va);
	else upd(m + 1, r, (cr << 1) | 1, ud, va);
	st[cr] = max(st[cr << 1], st[(cr << 1) | 1]);
}
int que(int l, int r, int cr, int al, int ar){ 
	if(ar < l || al > r) return -1;
	if(al <= l && ar >= r) return st[cr];
	int m = (l + r) >> 1;
	return max(que(l, m, cr << 1, al, ar), que(m + 1, r, (cr << 1) | 1, al, ar));
}
int ask(int u, int v){
	if(rt[u] == rt[v]) return que(1, N, 1, ps[v] + 1, ps[u]);
	return max(ask(pa[rt[u]], v), que(1, N, 1, ps[rt[u]], ps[u]));
}
int lca(int u, int v){
	while(rt[u] != rt[v]){
		if(de[u] < de[v]) v = pa[rt[v]];
		else u = pa[rt[u]];
	}
	return (de[u] < de[v])? u : v;
}
int main(){
//	freopen("in","r",stdin);
	int T;
	char M[10];
	scanf("%d", &T);
	while(T--){
		id = 0;
		scanf("%d",&N);
		for(int i = 0; i <= N; i++) g[i].clear(), c[i].clear();
		for(int i = 1, u, v, w; i < N; i++){
			scanf("%d %d %d", &u, &v, &w);
			g[u].emplace_back(v);
			g[v].emplace_back(u);
			c[u].emplace_back(w);
			c[v].emplace_back(w);
			e1[i] = u; e2[i] = v;
		}
		dfs(1, 0);
		hld(1);
		bld(1, N, 1);
		while(scanf("%s", M) && M[0] != 'D'){
			int j, k;
			scanf("%d %d", &j, &k);
			if(M[0] == 'Q'){
				int lc = lca(j, k);
				printf("%d\n",max(ask(j, lc), ask(k, lc)));
			}
			else upd(1, N, 1, (de[e1[j]] > de[e2[j]])? ps[e1[j]] : ps[e2[j]], k);
		}
	}
}