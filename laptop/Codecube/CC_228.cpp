#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;
const int X = 1e5 + 5;
int N, M, K, T;
vector<ii> g[X];
bool mm[X][2];
priority_queue<pair<ii, bool>> q;
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M >> K >> T;
	for(int i = 0, u, v, w; i < M; ++i){
		cin >> u >> v >> w;
		g[u].emplace_back(v, w), g[v].emplace_back(u, w);
	}
	q.emplace(ii(0, 1), 0);
	while(q.size()){
		auto [o, b] = q.top(); auto [w, x] = o; q.pop();
		if(mm[x][b]) continue; mm[x][b] = 1;
		if(w < -T) break;
		if(x == N) {cout << "Happy Winnie the Pooh :3\n" << -w; return 0;}
		for(auto [v, w2]: g[x]) {
			if(!mm[v][b]) q.emplace(ii(w - w2, v), b); 
			if(!b && !mm[v][1]) q.emplace(ii(w - K, v), 1);
		}
	}
	cout << "No Honey TT";
}