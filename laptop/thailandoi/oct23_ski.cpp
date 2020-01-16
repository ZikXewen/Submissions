#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define ii pair<int,int>
#define MXN 1005
#define MXL 2005
#define INF 2e9
using namespace std;
int N,M,T,S,V,u,v,w,mx;
bool vst[MXN][MXL];
vector<ii> ed[MXN];
void dfs(int cur,int mon){
	if(mon>V) return;
	vst[cur][mon]=true;
	for(ii i:ed[cur]) if(!vst[i.first][mon+i.second]) dfs(i.first,mon+i.second);
}
int main(){
	scanf("%d%d%d",&N,&T,&M);
	while(M--){
		scanf("%d%d",&u,&v);
		ed[u].emplace_back(v,0); 
	} scanf("%d",&M);
	while(M--){
		scanf("%d%d%d",&u,&v,&w);
		ed[u].emplace_back(v,w);
	}  scanf("%d%d",&S,&V);
	dfs(S,0);
	for(int i=1;i<=T;i++) for(int j=1;j<MXL;j++) if(vst[i][j]) mx=max(mx,j);
	printf("%d",V-mx);
}