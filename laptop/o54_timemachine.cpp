#include <cstdio>
#include <cmath>
#include <algorithm>
#define MXN 13
#define INF 2e9
using namespace std;
class ii{
public: int u,v,w;	
};
int L,W,M,ed[MXN][MXN],mem[MXN][1<<MXN];
ii n[MXN];
int dp(int cur,int bit){ //printf("%d",bit);
	if(cur==M) return 0;
	if(bit==(1<<(M+1))-1) return INF;
	if(mem[cur][bit]) return mem[cur][bit];
	int ret=INF;
	for(int i=1;i<=M;i++) if(!(bit&(1<<i))) ret=min(ret,dp(i,bit|(1<<i))+ed[cur][i]);
	return mem[cur][bit]=ret-n[cur].w;
}
int cal(int x1,int y1,int x2,int y2){
	return ceil(sqrt(double(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))));
}
int main(){
	scanf("%d%d%d",&L,&W,&M);
	for(int i=1;i<=M;i++) scanf("%d%d%d",&n[i].u,&n[i].v,&n[i].w);
	n[++M]={L-1,W-1,0};
	for(int i=0;i<=M;i++) for(int j=0;j<i;j++) ed[i][j]=ed[j][i]=cal(n[i].u,n[i].v,n[j].u,n[j].v);
	printf("%d",dp(0,1));
}
