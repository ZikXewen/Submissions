#include <bits/stdc++.h>
using namespace std;
const int X = 1005, MD = 1e9 + 7;
int N, k[3], dp[3][8][X], te[3][8][X], an;
vector<int> pr[3] = {{2}, {0}, {0, 1}};
auto add = [](int a, int b){return (a + b) % MD;};
int main(){
	scanf("%d %d %d %d", &N, k, k + 1, k + 2); dp[0][1][0] = 1;
	for(int i = 1; i < N; i++){
		for(int i = 0; i < 3; i++) for(int j = 0; j < 8; j++) copy(dp[i][j], dp[i][j] + k[i], te[i][j] + 1), te[i][j][0] = 0;
		for(int i = 0; i < 3; i++) for(int j = 0; j < 8; j++) if(j & (1 << i)) for(int v: pr[i])
			te[i][j][0] = add(accumulate(dp[v][j], dp[v][j] + k[v], 0, add), accumulate(dp[v][j ^ (1 << i)], dp[v][j ^ (1 << i)] + k[v], te[i][j][0], add));
		for(int i = 0; i < 3; i++) for(int j = 0; j < 8; j++) copy(te[i][j], te[i][j] + k[i], dp[i][j]);
	}
	for(int i = 0; i < 3; i++) an = accumulate(dp[i][7], dp[i][7] + k[i], an, add);
	printf("%d", an);
}
