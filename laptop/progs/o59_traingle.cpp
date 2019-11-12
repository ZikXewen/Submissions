#include <cstdio>
#include <algorithm>
using namespace std;
const long long mod = 1e9+7ll;
long long dp[105][105];
int N,M;
int main() {
	scanf("%d%d", &N, &M);
	for(int i = 0; i <= N; ++i) {
		for(int j = 0; j <= N; ++j) {
			if(i == 0 || j == 0) {dp[i][j] = 1; continue;}
			dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
			for(int k = 1; k <= M; ++k) {
				if(i-k-1 >= 0) dp[i][j] += dp[i-k-1][j-1];
				if(j-k-1 >= 0) dp[i][j] += dp[i-1][j-k-1];
			}
			dp[i][j] = (dp[i][j] + mod)%mod;
		}
	}
	printf("%lld", (dp[N][N]+mod-1)%mod);
}
