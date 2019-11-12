#include<cstdio>
#define ii pair<int,int>
#define MXN 1005
#define MXM 5005
using namespace std;
int N,M,x[MXM],y[MXM],A,B;
bool grd[MXN][MXN];
int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		scanf("%d%d",&x[i],&y[i]);
		grd[x[i]][y[i]]=grd[y[i]][x[i]]=true;
	}
	for(int i=0;i<M;i++) for(int j=i+1;j<M;j++){
		int ct=0;
		if(x[i]==x[j] || y[i]==y[j] || x[i]==y[j] || y[i]==x[j]) continue;
		if(grd[x[i]][y[j]]) ct++;
		if(grd[y[i]][x[j]]) ct++;
		if(grd[y[i]][y[j]]) ct++;
		if(grd[x[i]][x[j]]) ct++;
		if(ct==4) B++;
		if(ct==3) A++;
	}
	printf("%d",(A>>1)+B/3);
}
