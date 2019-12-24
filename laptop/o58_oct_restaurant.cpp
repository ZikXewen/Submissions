#include <bits/stdc++.h>
using namespace std;
const int X = 305;
int N, T, p[X];
vector<tuple<int, int, int>> ed;
vector<int> g[X];
int fd(int u) { return p[u] = p[u] == u? u : fd(p[u]); }
int main(){
	scanf("%d %d", &N, &T);
	for(int i = 0, w; i < N; i++) for(int j = 0; j < N; j++) { scanf("%d", &w); if(i < j) ed.emplace_back(w, i, j); }
	sort(ed.begin(), ed.end()); iota(p, p + N, 0);
	for(auto i: ed) {
		int u, v, w; tie(w, u, v) = i;
		int uu = fd(u), vv = fd(v);
		if(uu != vv) p[uu] = vv, g[u].emplace_back(v), g[v].emplace_back(u); 
	}
	for(int i = 0; i < N; i++) if(g[i].size() > 2) { printf("%d", i + 1); if(T ^ 1) printf("\n%d", g[i].size()); }
}
