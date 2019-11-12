#include <cstdio>
#include <cstring>
const int MOD=1e9+7;
using namespace std;
int N,M[3],an,dp[2][3][1004][8],walk[4][2]={{0,1},{1,2},{2,0},{0,2}};
int main(){
	scanf("%d%d%d%d",&N,&M[0],&M[1],&M[2]);
	N--;
	dp[N&1][0][1][1]=1;
	while(N--){
		memset(dp[N&1],0,sizeof dp[N&1]);
		for(int i=1;i<8;i+=2){
			for(int j=0;j<4;j++) for(int k=1;k<=M[walk[j][0]];k++) dp[N&1][walk[j][1]][1][i|(1<<walk[j][1])]=(dp[N&1][walk[j][1]][1][i|(1<<walk[j][1])]+dp[(N&1)^1][walk[j][0]][k][i])%MOD;
			for(int j=0;j<3;j++) for(int k=2;k<=M[j];k++) dp[N&1][j][k][i]=(dp[N&1][j][k][i]+dp[(N&1)^1][j][k-1][i])%MOD;
		}
	}
	for(int i=0;i<3;i++) for(int j=1;j<=M[i];j++) an=(an+dp[0][i][j][7])%MOD;
	printf("%d",an);
}
