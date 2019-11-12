#include <bits/stdc++.h>
using namespace std;
const int X = 3005;
int N, K, dp[X][X], an = INT_MAX, v[X];
int main(){
	scanf("%d %d", &N, &K);  	
	for(int i = 1; i <= N; i++) scanf("%d", &v[i]), dp[i][0] = INT_MAX - 2000;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j < min(K, i + 1); j++) dp[i][j] = min(dp[i][j-1], dp[i-j][K-j] + v[i]);
		for(int j = min(K, i + 1); j < K; j++) dp[i][j] = dp[i][j-1];
	}
	for(int i = N; i > N - K + 1; i--) an = min(an, dp[i][K - N - 1 + i]);
	printf("%d", an);
}
