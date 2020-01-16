#include <bits/stdc++.h>
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define x first
#define y second
using namespace std;
const int X = 5e4 + 5;
int N, M, L, S, T, ar[X];
vector<ii> g[X];
priority_queue<iii, vector<iii>, greater<iii>> q;
bool vs[X][32];
int main(){
	scanf("%d %d %d %d %d", &N, &M, &L, &S, &T); 
	for(int i = 1; i <= N; i++) scanf("%d", &ar[i]);
	for(int i = 0, u, v, w; i < M; i++) scanf("%d %d %d", &u, &v, &w), g[u].emplace_back(v, w);
	q.emplace(0, S, 1);
	while(q.size()){ 
		int u, cr, w; tie(w, u, cr) = q.top(); q.pop();
		if(vs[u][cr]) continue; vs[u][cr] = 1;
		if(u == T && cr > L) return !printf("%d", w);
		for(ii i: g[u]) if(!vs[i.x][(ar[i.x] == cr)? cr + 1 : cr]) q.emplace(w + i.y, i.x, (ar[i.x] == cr)? cr + 1 : cr);
	} printf("-1");
}
