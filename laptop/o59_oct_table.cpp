#include <bits/stdc++.h>
using namespace std;
const int X = 5e3 + 5, Y = 305;
int R, C, M, K, st[Y][X << 2], ar[Y][X];
void ud(int no, int at, int va, int l = 1, int r = C, int id = 1){
	if(l == r) { st[no][id] = va; return; }
	int m = (l + r) >> 1;
	if(at <= m) ud(no, at, va, l, m, id << 1);
	else ud(no, at, va, m + 1, r, id << 1 | 1);
	st[no][id] = min(st[no][id << 1], st[no][id << 1 | 1]);
}
int main() {
	freopen("in","r",stdin);
	scanf("%d %d %d", &R, &C, &M);
	while(M--) {
		scanf("%d", &K);
		int u, v, w;
		switch(K) {
		case 1 :
			scanf("%d %d %d", &u, &v, &w);
			ud(u, v, w); ar[u][v] = w;
			break;
		case 2 :
			scanf("%d %d", &u, &w);
			fill_n(st[u], C << 2, w);
			fill_n(ar[u], C + 1, w);
			break;
		case 3 :
			scanf("%d %d", &u, &v);
			printf("%d\n", ar[u][v]);
			break;
		default :
			int mn = 2e9;
			for(int i = 1; i <= R; i++) mn = min(mn, st[i][1]);
			printf("%d\n", mn);
		}
	}
}
/*
Bad test cases, should've been fixed for lazu prop only.
*/
