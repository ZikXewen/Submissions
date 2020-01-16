#include<iostream>
#define INF 1<<30
using namespace std;
int mem[51][51][51][51],a,N,M,ar[51][51];
int dp(int sx,int ex,int sy,int ey){
	if(mem[sx][ex][sy][ey]) return mem[sx][ex][sy][ey];
	if(sx==ex&&sy==ey) return 0;
	int ret=INF;
	for(int i=sx;i<ex;i++) ret=min(ret,dp(sx,i,sy,ey)+dp(i+1,ex,sy,ey));
	for(int i=sy;i<ey;i++) ret=min(ret,dp(sx,ex,sy,i)+dp(sx,ex,i+1,ey));
	return mem[sx][ex][sy][ey]=ret+ar[ex][ey]-ar[sx-1][ey]-ar[ex][sy-1]+ar[sx-1][sy-1];
}
int main(){
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++) for(int j=1;j<=M;j++){
		scanf("%d",&a);
		ar[i][j]=ar[i-1][j]+ar[i][j-1]-ar[i-1][j-1]+a;
	}
	printf("%d",dp(1,N,1,M));
}
