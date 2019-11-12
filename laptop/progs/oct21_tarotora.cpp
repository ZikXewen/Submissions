#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int N,K,a,b,C,dp[2][205];
int main(){
	scanf("%d",&C); while(C--){
		int mn=2e9;
		memset(dp,0,sizeof dp);
		scanf("%d%d",&N,&K);
		dp[N&1][101]=1;
		while(N--){
			//for(int i=301-K;i<=301+K;i++) printf("%d ",dp[N&1^1][i]); printf("\n");
			scanf("%d%d",&a,&b);
			memset(dp[N&1],0,sizeof dp[N&1]);
			for(int i=101-K;i<=101+K;i++) if(int x=dp[(N&1)^1][i]){
				if(dp[N&1][i-1]) dp[N&1][i-1]=min(dp[N&1][i-1],x+a); else dp[N&1][i-1]=x+a;
				if(dp[N&1][i+1]) dp[N&1][i+1]=min(dp[N&1][i+1],x+b); else dp[N&1][i+1]=x+b;
			}
		}
		for(int i=101-K;i<=101+K;i++) if(dp[0][i]) mn=min(mn,dp[0][i]);
		printf("%d\n",mn-1);
	}
}
