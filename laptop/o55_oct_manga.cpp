#include <bits/stdc++.h>
#define tup tuple<int, int, int>
#define ii pair<int, int>
using namespace std;
const int X = 5e4 + 5;
int N, M, K;
bool vs[X];
vector<tup> g[X]; 
bool dik(int id){
	priority_queue<ii, vector<ii>, greater<ii>> q;
	memset(vs, 0, sizeof vs);
	q.emplace(0, 1);
	while(q.size()){
		auto [w, u] = q.top(); q.pop();
		if(vs[u]) continue; vs[u] = 1;
		if(w > K) return 0;
		if(u == N) return 1;
		for(auto [v, nw, d]: g[u]) if(!vs[v] && d <= id) q.emplace(w + nw, v);
	}
	return 0;
}
int main(){
	scanf("%d %d %d", &N, &M, &K);
	for(int i = 1, u, v, w; i <= M; i++) scanf("%d %d %d", &u, &v, &w), g[u].emplace_back(v, w, i), g[v].emplace_back(u, w, i);
	int l = 1, r = M + 1;
	while(l < r){
		int m = (l + r) >> 1;
		if(dik(m)) r = m;
		else l = m + 1;
	}
	printf("%d", l == (M + 1)? -1 : l);
}
