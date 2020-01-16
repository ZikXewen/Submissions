#include <bits/stdc++.h>
using namespace std;
int N, M, dp[(int)2e5 + 5];
vector<int> pt;
int main(){
	scanf("%d %d", &N, &M);
	for(int i = 0, u, v, w; i < M; i++){
		scanf("%d %d %d", &u, &v, &w);
		int mu = w, mv = w, an = 0;
		for(int x: pt) an = max(an, dp[x]), mv = max(mv, dp[x] + w - abs(x - u)), mu = max(mu, dp[x] + w - abs(x - v));
		pt.emplace_back(u), pt.emplace_back(v); dp[u] = mu, dp[v] = mv, an = max({an, mu, mv});
		printf("%d\n", an);
	}
}
