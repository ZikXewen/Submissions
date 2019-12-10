#include <bits/stdc++.h>
using namespace std;
const int X = 2e5 + 5;
int N, M, st[2][X << 2];
void ud(int po, int va, int l = 1, int r = N, int id = 1){
	if(l == r){st[0][id] = va + po; st[1][id] = va - po; return;}
	int m = (l + r) >> 1;
	ud(po, va, l, m, id << 1); ud(po, va, m + 1, r, id << 1 | 1);
	st[0][id] = max(st[0][id << 1], st[0][id << 1 | 1]);
	st[1][id] = max(st[1][id << 1], st[1][id << 1 | 1]);
}
int qu(int ty, int al, int ar, int l = 1, int r = N, int id = 1){
	if()
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;
	for(int i = 0, u, v, w; i < M; ++i){
		cin >> u >> v >> w;
		vv = w + max(qu(0, 1, u) - u, qu(1, u, N) + u);
		uu = w + max(qu(0, 1, v) - u, qu(1, v, N) + u);
		ud(v, vv), ud(u, uu);
	}
}