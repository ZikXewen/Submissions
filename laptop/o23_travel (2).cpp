#include <cstdio>
#include <vector>
#include <cmath>
#define MXN 30005
using namespace std;
int n,m,u,v, l,tin[MXN],tout[MXN],dist[MXN],timer,q[2]={1,1},ret;
vector<int> adj[MXN],up[MXN];
void dfs(int v, int p){
	tin[v] = ++timer;
	dist[v]=dist[p]+1;
	up[v][0] = p;
	for (int i = 1; i <= l; ++i) up[v][i] = up[up[v][i-1]][i-1];
	for (int u : adj[v]) if (u != p) dfs(u, v);
	tout[v] = ++timer;
}
bool ck(int u, int v){
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}
int lca(int u, int v){
	if (ck(u, v)) return u;
	if (ck(v, u)) return v;
	for (int i = l; i >= 0; --i) if (!ck(up[u][i], v)) u = up[u][i];
	return up[u][0];
}
void cal(int root) {
	l = ceil(log2(n));
	for(int i=0;i<MXN;i++) up[i].resize(l+1);
	dfs(root, root);
}
int main(){
	scanf("%d",&n); for(int i=1;i<n;i++){scanf("%d%d",&u,&v); adj[u].emplace_back(v); adj[v].emplace_back(u); }
	cal(1);  scanf("%d",&m);
	while(m--){
		scanf("%d",&q[m&1]); 
		n=lca(q[0],q[1]);
		//printf("%d %d\n",dist[q[1]],dist[q[0]]);
		ret+=dist[q[1]]+dist[q[0]]-(dist[n]<<1);
	}
	printf("%d",ret);
}
