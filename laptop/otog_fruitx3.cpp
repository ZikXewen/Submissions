#include<cstdio>
#include<algorithm>
using namespace std;
int N,M,v[17][17],mem[17][17];
int dp(int x,int y){
	if(!x||!y) return 0;
	if(mem[x][y]) return mem[x][y];
	return max(dp(x-1,y),dp(x,y-1))+v[x][y];
}
int main(){
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) scanf("%d",&v[i][j]);
	mem[1][1]=v[1][1];
	printf("%d",dp(N,M));
}
