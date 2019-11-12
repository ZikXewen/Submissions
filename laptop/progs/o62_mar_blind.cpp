#include <bits/stdc++.h>
#define iii tuple<int, int, int, int>
using namespace std;
const int X = 2e4 + 5;
int N, W, din[X], pa[X];
vector<iii> ve;
vector<int> gr[X];
set<int> s, g[X];
queue<int> q;
int fd(int u){ return pa[u] = pa[u] == u? u : fd(pa[u]); }
int main(){
	iota(pa, pa + X, 0);
	scanf("%d %d", &N, &W);
	for(int i = 0, t, u, v, w; i < W; i++) {
		scanf("%d %d %d %d", &t, &u, &v, &w);
		if(t == 3) pa[fd(u)] = pa[fd(v)] = fd(w);
		else ve.emplace_back(t - 1, u, v, w);
	}
	for(int i = 1; i <= N; i++)  gr[fd(i)].emplace_back(i), s.emplace(fd(i));
	printf("%d\n", s.size());
	for(iii x: ve) {
		int t, u, v, w; tie(t, u, v, w) = x;
		if(t) g[fd(u)].emplace(fd(v)), g[fd(u)].emplace(fd(w));
		else g[fd(v)].emplace(fd(u)), g[fd(w)].emplace(fd(u));
	}
	for(int i: s) for(int j: g[i]) din[j]++;
	for(int i: s) if(!din[i]) q.emplace(i);
	while(!q.empty()){
		int u = q.front(); q.pop();
		printf("%d ", gr[u].size());
		for(int i: gr[u]) printf("%d ", i);
		printf("\n");
		for(int v: g[u]) 	if(!--din[v]) q.emplace(v);
	}
}
