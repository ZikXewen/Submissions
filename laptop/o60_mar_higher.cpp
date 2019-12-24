#include <bits/stdc++.h>
using namespace std;
const int X = 1e6 + 5;
int N, K, st[X << 1];
void ud(int x, int va){ for(st[x += N] = va; x - 1; x >>= 1) st[x >> 1] = max(st[x], st[x ^ 1]); }
int gt(int l, int r){
	int re = 0;
	for(l += N, r += N + 1; l < r; l >>= 1, r >>= 1){
		if(l & 1) re = max(re, st[l++]);
		if(r & 1) re = max(re, st[--r]);
	}
	return re;
}
int main(){
	scanf("%d %d", &N, &K);
	while(K--){
		int u, v, l = 0, r = N;
		scanf("%d %d", &u, &v);
		ud(u, v);
		while(l < r){
			int m = (l + r + 1) >> 1;
			if(gt(max(u - m, 0), min(u + m, N - 1)) == v) l = m;
			else r = m - 1;
		}
		printf("%d\n", l);	
	}
}
