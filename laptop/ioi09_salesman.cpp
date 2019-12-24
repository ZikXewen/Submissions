#include <bits/stdc++.h>
using namespace std;
const int X = 5e5 + 5;
int N, U, D, S, ti[X], lo[X], mo[X], ar[X], dp[X];
int co(int u, int v){
	u = ar[u],v = ar[v];
	if(lo[u] > lo[v]) return U * (lo[u] - lo[v]);
	return D * (lo[v] - lo[u]);
}
int main(){
	scanf("%d %d %d %d", &N, &U, &D, &lo[0]);
	for(int i = 1; i <= N; i++) scanf("%d %d %d", &ti[i], &lo[i], &mo[i]);
	lo[N + 1] = lo[0]; ti[N + 1] = X; N += 2;
	iota(ar, ar + N, 0); sort(ar, ar + N, [](int l, int r){return ti[l] < ti[r];});
	fill_n(dp, N, -1e9); dp[0] = 0;
	for(int i = 1; i < N; i++) {for(int j = 0; j < N - 1; j++) dp[i] = max(dp[i], dp[j] - co(i, j)); dp[i] += mo[ar[i]];}
	printf("%d", dp[N - 1]);
}
