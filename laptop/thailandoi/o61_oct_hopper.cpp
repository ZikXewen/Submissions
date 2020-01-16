#include <bits/stdc++.h>
using namespace std;
const int MXN = 3005;
int N, M, v[MXN], mm[MXN];
vector<int> g[MXN];
int dfs(int u){
	if(!mm[u]) for(int v: g[u]) mm[u] = max(mm[u], dfs(v) + 1);
	return mm[u]? mm[u] : ++mm[u];
}
int main(){
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++) scanf("%d", &v[i]);
	int l = 0, r = N - 1, pv = 0;
	while(l < r){
		memset(mm, 0, sizeof mm);
		int m = (l + r) >> 1;
		if(m > pv)for(int i = pv; i <= m; i++) for(int j = 0; j < N; j++) if(v[(j + i) % N] > v[j]) g[j].emplace_back((j + i) % N);
		if(m < pv) for(int i = 0; i < N; i++) while(g[i].size() && ((g[i].back() - i + N) % N) > m) g[i].pop_back();
		bool ps = 0;
		for(int i = 0; i < N; i++) if(dfs(i) > M) { ps = 1; break; }
		pv = m;
		if(ps) r = m;
		else l = m + 1;
	}
	printf("%d", l);
}
