#include<bits/stdc++.h>
using namespace std;
const int X = 2e5 + 5;
int N, M, g[X], p[X], po[X];
void dfs(int u, int pa){
	p[u] = p[pa], po[u] = po[pa] + 1;
	if(!p[g[u]]) dfs(g[u], u);
}
bool que(int s, int e, int a, int b){
	if(p[s] == p[e]){
		if(p[a] == p[s] and p[b] == p[s]){
			if(po[s] > po[e]) swap(s, e);
			return (po[s] <= po[a] and po[a] < po[e]) ^ (po[s] <= po[b] and po[b] < po[e]);
		}
		else return 0;
	}
	else return !(p[s] == p[a] and p[e] == p[b]) and !(p[s] == p[b] and p[e] == p[a]);
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;
	for(int i = 1; i <= N; ++i) cin >> g[i];
	for(int i = 1; i <= N; ++i) if(!p[i]) dfs(p[i] = i, i); 
	for(int i = 0, s, e, a, b; i < M; ++i) cin >> s >> e >> a >> b, cout << (que(s, e, a, b)? "SURVIVE" : "DEAD") << '\n';
}