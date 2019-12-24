#include <bits/stdc++.h>
#define iii tuple<long long, int, int, int>
#define ii pair<int, int>
#define x first
#define y second
using namespace std;
const int X = 8e4 + 10;
int N, M, L, Q, no;
bool mk[X], vs[X][9][10];
map<int, int> mp;
vector<ii> g[X];
priority_queue<iii, vector<iii>, greater<iii>> q;
int main(){
	scanf("%d %d %d %d", &N, &M, &L, &Q);
	for(int i = 0, u, v, w; i < M; i++) scanf("%d %d %d", &u, &v, &w), g[u].emplace_back(v, w);
	for(int i = 0, u; i < L; i++) scanf("%d", &u), mk[u] = 1, mp[u] = no++;
	q.emplace(0LL, 1, 0, -1);
	while(q.size()){
		iii u = q.top(); q.pop();
		long long b; int a, c, d; tie(b, a, c, d) = u;
		if(vs[a][c][d]) continue; vs[a][c][d] = 1;
		if(a == N) return !printf("%lld", b);
		bool dr = (mk[a] && mp[a] != d && c < Q);
		for(ii i: g[a]) {
			if(dr && !vs[i.x][c + 1][mp[a]]) q.emplace(b + (i.y >> (c + 1)), i.x, c + 1, mp[a]);
			if(!vs[i.x][c][d]) q.emplace(b + (i.y >> c), i.x, c, d);
		}
	}
}
