#include <bits/stdc++.h>
#define ii pair<int, int>
#define iii tuple<long long, int, int>
using namespace std;
const int X = 5e4 + 5;
string xmas, ls;
int N, M, va[X], st;
long long mm[X][20];
vector<ii> g[X];
priority_queue<iii, vector<iii>, greater<iii>> q;
int fn(int u, int v){
	if(va[v] == -1) return u;
	return u | (1 << va[v]);
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M >> xmas >> ls;
	for(int i = 0; i < ls.length(); ++i)
		if(ls[i] == 'X') va[i + 2] = 0;
		else if(ls[i] == 'M') va[i + 2] = 1;
		else if(ls[i] == 'A') va[i + 2] = 2;
		else if(ls[i] == 'S') va[i + 2] = 3;
		else va[i + 2] = -1;
	for(int i = 0, u, v, w; i < M; ++i) cin >> u >> v >> w, g[u].emplace_back(v, w), g[v].emplace_back(u, w);
	for(int i = 0; i < 4; ++i) if(xmas[i] != '_') st |= (1 << i);
	memset(mm, -1, sizeof mm); q.emplace(0, N, fn(st, N));
	while(q.size()){
		auto [u, v, w] = q.top(); q.pop();
		if(mm[v][w] != -1) continue; mm[v][w] = u;
		if(v == 1 && w == 15) {cout << u; return 0;}
		for(auto [j, k]: g[v]) if(mm[j][fn(w, j)] == -1) q.emplace(u + k, j, fn(w, j));
	}
}
