#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define INF 2e9
#define MXL 2000005
#define MXN 1005
using namespace std;
int dist(int ax,int ay,int bx,int by){
	return abs(ax-bx)+abs(ay-by);
}
int N,M,fx[MXN],fy[MXN],a,b,an,m[MXL];
int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++) scanf("%d%d",&fx[i],&fy[i]);
	for(int i=0;i<M;i++){
		int x=INF;
		scanf("%d%d",&a,&b);
		for(int i=0;i<N;i++) x=min(x,dist(fx[i],fy[i],a,b));
		an=max(an,++m[x]);
	}
	printf("%d",an);
}