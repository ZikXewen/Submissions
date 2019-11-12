#include <bits/stdc++.h>
#define ii pair<int, int>
#define x first
#define y second
#define iii tuple<int, int, int>
using namespace std;
const int X = 1e5 + 5;
int N, M, K;
bool vs[X][6];
vector<ii> g[X];
priority_queue<iii, vector<iii>, greater<iii>> q;
int main(){
	scanf("%d %d %d", &N, &M, &K);
	for(int i = 0, u, v, w; i < M; i++) scanf("%d %d %d", &u, &v, &w), g[u].emplace_back(w, v);
	q.emplace(0, 1, 0);
	while(q.size()){
		int u, v, w; tie(w, u, v) = q.top(); q.pop();
		if(vs[u][v]) continue; vs[u][v] = 1;
		if(u == N) return !printf("%d", w);
		for(ii i: g[u]){
			if(i.x < -100) {if(v < K  && !vs[i.y][v + 1]) q.emplace(w, i.y, v + 1);}
			else if(!vs[i.y][v]) q.emplace(w + max(i.x, 0), i.y, v);
		}
	}
	printf("-1");
}
