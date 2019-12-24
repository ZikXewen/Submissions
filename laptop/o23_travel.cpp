#include<cstdio>
#include<vector>
#define MXN 30005
using namespace std;
int dist[MXN],par[MXN],N,M,a,b;
vector<int> v[MXN];
void dfs(int cur,int prev){
	dist[st]=dist[prev]+1;
	par[cur]=prev;
	for(int i:v[st]) if(i!=prev) dfs(i,cur);
}
int main(){
	scanf("%d",&N);
	while(N--){
		scanf("%d%d",&a,&b);
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	dfs(1,0);
	scanf("%d",&M);
	while(M--){
		scanf("%d",&a);
		printf("%d\n",dist[a]);
	}
}