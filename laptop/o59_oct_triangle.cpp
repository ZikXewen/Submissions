#include <bits/stdc++.h>
using namespace std;
const int X = 105, MD = 1e9 + 7;
int N, K, mm[X][X];
int dp(int u, int v){
	if(mm[u][v]) return mm[u][v];
	mm[u][v] = ((dp(u - 1, v) + dp(u, v - 1)) % MD - dp(u - 1, v - 1) + MD) % MD;
	for(int i = 2; i <= min(u, K); i++) mm[u][v] = (mm[u][v] + dp(u - i, v - 1)) % MD;
	for(int i = 2; i <= min(v, K); i++) mm[u][v] = (mm[u][v] + dp(u - 1, v - i)) % MD;
	return mm[u][v];
}
int main(){
	scanf("%d %d", &N, &K); K++;
	for(int i = 0; i <= N; i++) mm[0][i] = mm[i][0] = 1;
	printf("%d", (dp(N, N) + MD - 1) % MD);
	/*for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++){
		mm[i][j] = (((mm[i][j - 1] + mm[i - 1][j]) % MD) - mm[i - 1][j - 1] + MD) % MD;
		for(int k = 2; k <= min(i, K); k++) mm[i][j] = (mm[i][j] + mm[i - k][j - 1]) % MD;
		for(int k = 2; k <= min(j, K); k++) mm[i][j] = (mm[i][j] + mm[i - 1][j - k]) % MD;
	}
	printf("%d", (mm[N][N] + MD - 1) % MD);*/
}
