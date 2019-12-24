	#include <bits/stdc++.h>
	#define ii tuple<int, int, int, int>
	using namespace std;
	int N, M, S;
	int dx[3] = {0, 1, 0}, dy[3] = {1, 0, -1};
	char tem;
	priority_queue<ii, vector<ii>, greater<ii>> q;
	int main(){
		scanf("%d %d %d", &N, &M, &S);
		vector<vector<bool>> ar(N + 5, vector<bool>(M + 5));
		vector<vector<vector<bool>>> vs(3, vector<vector<bool>>(N + 5, vector<bool>(M + 5)));
		for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) scanf(" %c", &tem), ar[i][j] = (tem == '.');
		q.emplace(0, 1, S, 1);
		while(!q.empty()){
			int u, v, w, di; tie(w, di, u, v) = q.top(); q.pop();
			if(vs[di][u][v]) continue; vs[di][u][v] = 1;
			if(v == M) return !printf("%d", w);
			for(int i = 0; i < 3; i++) {
				if(ar[u + dy[i]][v + dx[i]] && !vs[i][u + dy[i]][v + dx[i]]) q.emplace(w + (di != i), i, u + dy[i], v + dx[i]);
			}
		}
		printf("-1");
	}
