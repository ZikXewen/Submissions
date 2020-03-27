#include <bits/stdc++.h>
using namespace std;
const int X = 1e5 + 5;
int N, M, ar[X], st[X << 1];
void bd(){
	for(int i = 0; i < N; ++i) st[N + i] = ar[i];
	for(int i = N - 1; i > 0; --i) st[i] = st[i << 1] + st[i << 1 | 1];
}
void ud(int po, int va){
	st[po += N] = va;
	for(int i = po; i > 1; i >>= 1) st[i >> 1] = st[i] + st[i ^ 1];
}
int qu(int l, int r){
	int ret = 0;
	for(l += N, r += N; l < r; l >>= 1, r >>= 1){
		if(l & 1) ret += st[l++];
		if(r & 1) ret += st[--r];
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;
	for(int i = 0; i < N; ++i) cin >> ar[i];
	bd();
	for(int i = 0, u, v, w; i < M; ++i) {
		cin >> u >> v >> w;
		if(!u) ud(v, w);
		else cout << qu(v, w + 1) << '\n';
	}
}
/*
10 5
1 2 3 4 5 6 7 8 9 10
1 2 4
1 1 10
0 5 2
1 1 10
1 4 6
*/