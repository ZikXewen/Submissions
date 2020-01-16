#include <bits/stdc++.h>
#define ii pair<int, int>
#define iii tuple<long long, int, int>
using namespace std;
const int MX = 1e4 + 5;
int N, M, T, X, Y;
bool mm[MX][8];
vector<ii> g[MX];
priority_queue<iii, vector<iii>, greater<iii>> q;
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M >> T >> X >> Y;
	for(int i = 0, u, v, w; i < M; ++i) cin >> u >> v >> w, g[u].emplace_back(v, w);
	q.emplace(0, X, 1 % T);
	while(q.size()){
		auto [u, v, w] = q.top(); q.pop();
		if(mm[v][w]) continue; mm[v][w] = 1;
		if(v == Y && !w) {cout << u; return 0;}
		for(auto [a, b] : g[v]) if(!mm[a][(w + 1) % T]) q.emplace(u + b, a, (w + 1) % T);
	} cout << -1;
}
