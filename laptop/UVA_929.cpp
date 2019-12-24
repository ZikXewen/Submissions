#include <bits/stdc++.h>
#define MXN 1000
using namespace std;
class iii{public:int x,y,w; };
bool operator<(const iii&A,const iii &B) {return A.w>B.w;}
int Z,N,M,t[MXN][MXN],dx[4]={0,1,0,-1},dy[4]={1,0,-1,0},dist[MXN][MXN]; bool vst[MXN][MXN];
int main(){
//	freopen("input","r",stdin); freopen("output","w",stdout);
	scanf("%d",&Z); while(Z--){
	priority_queue<iii> q; memset(dist,0,sizeof dist); memset(vst,0,sizeof vst);
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++) for(int j=0;j<M;j++) scanf("%d",&t[i][j]);
	q.push({0,0,t[0][0]}); vst[0][0]=true;
	while(!q.empty()){
		iii x=q.top(); q.pop();
		dist[x.x][x.y]=x.w;
		if(x.x==N-1&&x.y==M-1) break;
		for(int i=0;i<4;i++) {
			if(x.x+dx[i]<0||x.x+dx[i]==N||x.y+dy[i]<0||x.y+dy[i]==M||vst[x.x+dx[i]][x.y+dy[i]]) continue;
			vst[x.x+dx[i]][x.y+dy[i]]=true;//dist[x.x+dx[i]][x.y+dy[i]]=x.w+t[x.x+dx[i]][x.y+dy[i]];
			q.push({x.x+dx[i],x.y+dy[i],x.w+t[x.x+dx[i]][x.y+dy[i]]});
		}
	}
	printf("%d\n",dist[N-1][M-1]);
}
}
