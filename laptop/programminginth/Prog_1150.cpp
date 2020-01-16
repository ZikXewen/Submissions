#include <cstdio>
#include <cstring>
using namespace std;
int N,a;
bool dp[2][60001];
int f(int x){
	if(x<0) return x+60001;
	if(x>60000) return x-60001;
	return x;
}
int main(){
	scanf("%d",&N);
	dp[N&1][30000]=true;
	while(N--){
		memset(dp[N&1],false,sizeof dp[N&1]);
		scanf("%d",&a);
		for(int i=0;i<=60000;i++) if(dp[(N&1)^1][i]) dp[N&1][f(i+a)]=dp[N&1][i]=true;
	}
	for(int i=60000;i>=0;i--) if(dp[0][i]) {printf("%d",i-30000); return 0;}
}
	
