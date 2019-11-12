#include<cstdio>
#include<algorithm>
#define INF 2e9
using namespace std;
int a,b,vst[11][11][3][103],N,v[11][11]; //bool vst[11][11][3][11];
bool ck(int x,int y,int f,int cur){
	return x>=0&&x<N&&y>=0&&y<N&&!vst[x][y][f][cur];
}
int dp(int x,int y,int f,int cur){ printf("%d %d %d %d %d\n",x,y,f,cur,v[x][y]);
	if(vst[x][y][f][cur]) return vst[x][y][f][cur];
	if(cur==v[x][y]){
		cur++; if(cur>N*N) return 0;
	}
	int ret=INF;
	vst[x][y][f][cur]=true;
	if(f==0){
		for(int i=0;i<N;i++) if(!vst[i][y][f][cur]) ret=min(ret,dp(i,y,f,cur));
		for(int i=0;i<N;i++) if(!vst[x][i][f][cur]) ret=min(ret,dp(x,i,f,cur));
	}
	if(f==1){
		for(int i=1-N;i<N;i++) if(ck(x+i,y+i,f,cur)) ret=min(ret,dp(x+i,y+i,f,cur));
		for(int i=1-N;i<N;i++) if(ck(x+i,y-i,f,cur)) ret=min(ret,dp(x+i,y-i,f,cur));
	}
	if(f==2){
		if(ck(x+1,y+2,f,cur)) ret=min(ret,dp(x+1,y+2,f,cur));
		if(ck(x+1,y-2,f,cur)) ret=min(ret,dp(x+1,y-2,f,cur));
		if(ck(x-1,y+2,f,cur)) ret=min(ret,dp(x-1,y+2,f,cur));
		if(ck(x-1,y-2,f,cur)) ret=min(ret,dp(x-1,y-2,f,cur));
		if(ck(x+2,y+1,f,cur)) ret=min(ret,dp(x+2,y+1,f,cur));
		if(ck(x+2,y-1,f,cur)) ret=min(ret,dp(x+2,y-1,f,cur));
		if(ck(x-2,y+1,f,cur)) ret=min(ret,dp(x-2,y+1,f,cur));
		if(ck(x-2,y-1,f,cur)) ret=min(ret,dp(x-2,y-1,f,cur));
	}
	for(int i=0;i<3;i++) if(i!=f&&!vst[x][y][f][cur]) ret=min(ret,dp(x,y,i,cur));
	//vst[x][y][f][cur]=false;
	return vst[x][y][f][cur]=ret+1;
}
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++) for(int j=0;j<N;j++) scanf("%d",&v[i][j]);
	for(int i=0;i<N;i++) for(int j=0;j<N;j++) if(v[i][j]==1){a=i;b=i;break;}
	
	printf("%d",min(min(dp(a,b,0,2),dp(a,b,1,2)),dp(a,b,2,2)));
}
