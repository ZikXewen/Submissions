#include <bits/stdc++.h>
#define iii tuple<int, int, int>
using namespace std;
const int X = 105;
int K, C, N, R, T, sr, sc; char te;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
bool vs[X][X], g[X][X], vs2[X][X], fd;
priority_queue<iii, vector<iii>, greater<iii>> q;
int main(){
	 freopen("in","r",stdin);
	scanf("%d", &K);
	while(K--){
		memset(vs, 0, sizeof vs), memset(vs2, 0, sizeof vs2), memset(g, 0, sizeof g), fd = 0;
		scanf("%d %d %d %d %d %d", &R, &C, &N, &T, &sr, &sc);
		for(int i = 0, u, v, w; i < N; i++) scanf("%d %d %d", &u, &v, &w), q.emplace(u, v + 1, w + 1);
		for(int i = 1; i <= R; i++) for(int j = 1; j <= C; j++) scanf(" %c", &te), g[i][j] = (te == '.');
		while(q.size()){
			int u, v, w; tie(w, u, v) = q.top(); q.pop();
			if(vs[u][v]) continue; vs[u][v] = 1;
			if(w < T) for(int i = 0; i < 4; i++) if(g[u + dx[i]][v + dy[i]] && !vs[u + dx[i]][v + dy[i]]) q.emplace(w + 1, u + dx[i], v + dy[i]);
		}
		q.emplace(0, sr + 1, sc + 1);
		while(q.size()){
			int u, v, w; tie(w, u, v) = q.top(); q.pop();
			if(vs2[u][v]) continue; vs2[u][v] = 1;
			if(!vs[u][v]) fd = 1;
			if(w < T) for(int i = 0; i < 4; i++) if(g[u + dx[i]][v + dy[i]] && !vs2[u + dx[i]][v + dy[i]]) q.emplace(w + 1, u + dx[i], v + dy[i]);
		}
		printf("%s\n", fd? "YES" : "NO");
	}
}
