#include <bits/stdc++.h>
#define long long long
using namespace std;
const int X = 1e5 + 5, Y = 105, MD = 1e9 + 7;
int N, M, dp[X][Y] = {1}; // ver, at
long an[Y];
void md(long &u){u = ((u % MD) + MD) % MD;};
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;
	for(int i = 1, u; i <= N; ++i){
		cin >> u;
		for(int j = 0; j <= 100; ++j) 
			dp[i][j] = (dp[i - 1][j] + (j >= u? dp[i - 1][j - u] : 0)) % MD;
	}
	for(int i = 0, u, v, w; i < M; ++i){
		cin >> u >> v >> w;
		for(int j = 0; j <= w; ++j){
			an[j] = dp[v][j];
			for(int k = 0; k < j; ++k) md(an[j] -= an[k] * dp[u - 1][j - k]);
		}
		cout << an[w] << '\n';
	}
}