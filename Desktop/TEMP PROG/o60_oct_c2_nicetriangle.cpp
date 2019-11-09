#include <bits/stdc++.h>
using namespace std;
const int MOD = 29947;
const int N = 705;
int x,y,z,dp[N][N];
int main() {
	scanf("%d%d%d",&x,&y,&z);
	x--, y--, z--;
	for(int i=0; i<N;i++) for(int j=0;j<N;j++)
		if(!i||!j) dp[i][j] = 1;
		else dp[i][j] = (dp[i-1][j]+dp[i][j-1])%MOD;
	int ans=dp[x+y][z];
	for(int i=1;i<=x;i++) for(int j=1;j<=y;j++)
		ans=(ans+(dp[i-1][j-1]*dp[x+y-i-j][z])%MOD)%MOD;
	printf("%d",ans);
	return 0;
}
