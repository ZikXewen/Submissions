#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MXN = 135;
const int INF = 2e9;
int n, m,cost;
long long bt[MXN], dp[MXN][MXN],cbt[MXN],cdp[MXN][MXN];
int A[MXN];
int main() {
	scanf("%d%d", &n, &m);
	int lm =1<<m, im=1<<(m-1);  // lm = 2^m // im=2^m-1
	fill(dp[0], dp[MXN-1] + MXN, -INF);
	for(int i = 0; i < lm; ++i) {
		scanf("%d", &cost);
		A[i] = dp[i>>1][i] = dp[im|i>>1][i] = cost; 
	}
	for(n -= m-1; n > 0; n >>= 1) {
		if(n & 1) {
			memset(cbt,0,sizeof cbt);
			for(int i = 0; i < lm; ++i) for(int j = 0; j < lm; ++j) if(cbt[j] < bt[i] + dp[i][j]) cbt[j] = bt[i] + dp[i][j];
			for(int i = 0; i < lm; ++i) bt[i] = cbt[i];
		}
		for(int i = 0; i < lm; ++i) for(int j = 0; j < lm; ++j) for(int k = 0; k < lm; ++k) cdp[i][j] = max(cdp[i][j], dp[i][k] + dp[k][j]);
		for(int i = 0; i < lm; ++i) for(int j = 0; j < lm; ++j) dp[i][j] = cdp[i][j];
	}
	printf("%lld", *max_element(bt, bt+MXN));
}
