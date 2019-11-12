#include <cstdio>
#include <algorithm>
using namespace std;
const int MXN=3005, INF=2e9;
int N,K, A[MXN], dp[MXN][MXN],mn=INF;
int main() {
	scanf("%d%d",&N,&K);
	for(int i=1;i<=N;i++) {scanf("%d",&A[i]); dp[i][0]=INF;}
	for(int i=1;i<=N;i++) for(int j=1;j<K;j++) dp[i][j] = min(dp[i][j-1],dp[max(i-j,0)][K-j]+A[i]);
	for(int i=N;i>N-K+1;i--) mn=min(mn,dp[i][K-(N-i)-1]);
	printf("%d",mn);
}
