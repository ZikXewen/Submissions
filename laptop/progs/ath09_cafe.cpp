#include <bits/stdc++.h>
using namespace std;
const int X = 1e3 + 5;
int T, N, mm[X][3];
vector<int> g[X];
int dfs(int u, int p){
	int mm[u][0] = 0;
	for(auto v : g[u]) if(v != p) {
		re = max(re, dp(v, u));
		mm[u][1] = max(mm[u][1], mm[v][0]);
		mm[u][2] = max(mm[u][2], mm[v][1]);
	}
	if(!cr) for(auto v : g[u]) if(v != p) re += max(dfs(v, u, 0), dfs(v, u, 1) + 1);
	else if(cr & 1) for(auto v : g[u]) if(v != p) re = max({re, dfs(v, u, 0), dfs(v, u, 2) + 1});
	else for(auto v : g[u]) if(v != p) re += max(re, dfs(v, u, 0));
	return mm[u][cr] = re;
}
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) g[i].clear();
		memset(mm, -1, sizeof mm);
		for(int i = 1, u, v; i < N; ++i) scanf("%d %d", &u, &v),
			g[u].emplace_back(v), g[v].emplace_back(u);
		printf("%d\n", max(dfs(1, 0, 1) + 1, dfs(1, 0, 0)));
	}
}
