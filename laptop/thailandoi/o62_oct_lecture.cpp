#include <bits/stdc++.h>
using namespace std;
const int X = 1e5 + 5, Y = 305;
int C, N, M, po[X], le[X], di[Y][Y];
int main(){
	scanf("%d %d %d", &C, &N, &M);
	for(int i = 0; i < C; i++) scanf("%d", &po[i]);
	for(int i = 0; i < C; i++) scanf("%d", &le[i]);
	for(int i = 1; i <= N; i++) fill_n(di[i] + 1, N, 1e9);
	for(int i = 0, u, v, w; i < M; i++) scanf("%d %d %d", &u, &v, &w), di[u][v] = di[v][u] = w;
	for(int i = 0; i <= N; i++) di[i][i] = 0;
	for(int k = 1; k <= N; k++) for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++) di[i][j] = min(di[i][j], di[i][k] + di[k][j]);
	int l = 1, r = 1e9;
	while(l < r){
		int m = (l + r + 1) >> 1, lf = 0; bool no = 0;
		for(int i = 0; i < C; i++){ 
			if(le[i] < lf) {no = 1; break;}
			lf = max((m * di[po[i]][po[i + 1]]) + lf - le[i], 0);
		}
		if(no) r = m - 1;
		else l = m;
	}
	printf("%d", l);
}
