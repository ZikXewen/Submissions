#include<cstdio>
#include<algorithm>
#include<iostream>
#define MOD 2553
using namespace std;
int N, K, ans, dp[5001][2];
int main() {
    scanf("%d%d",&N,&K);
    for(int i=1;i<=N;i++) {
        if(i<=K) dp[i][1]=(dp[i-1][1]+1)%MOD;
        else dp[i][1]=dp[i-1][1];
    }
    if(K==N) ans++;
    for(int len = 2; len <= N; len++) {
    	bool b=len&1;
        for(int i = 1; i <= N; i++) dp[i][b] = (dp[i-1][b]+dp[i-1][!b]-dp[max(i-K-1, 0)][!b])%MOD;
        int res = (dp[N][b] - dp[N-1][b] + MOD)%MOD;
        ans += (((res*res)%MOD)*res)%MOD;
        ans %= MOD;
    }
    printf("%d",ans);
}
