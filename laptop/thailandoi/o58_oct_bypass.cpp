#include <bits/stdc++.h>
using namespace std;
const int X = 1e5 + 5;
int dp[X][2], N, cd[X];
long long an;
vector<int> g[X];
void dfs(int u, int p){
	cd[u] = 1;
	for(int v: g[u]) if(v != p){
		dfs(v, u);
		cd[u] += cd[v];
		an = max(an, 1ll * (N - cd[v]) * dp[v][1]);
		an = max(an, 1ll * dp[u][0] * dp[v][0]);
		dp[u][0] = max(dp[u][0], cd[v]);
		an = max(an, 1ll * dp[u][1] * cd[v]);
		dp[u][1] = max(dp[u][1], dp[v][0]);
	}
}
int main(){
	scanf("%d", &N);
	for(int i = 1, u, v; i < N; i++) scanf("%d %d", &u, &v), g[u].emplace_back(v), g[v].emplace_back(u);
	dfs(1, 0);
	printf("%lld", an);
}
