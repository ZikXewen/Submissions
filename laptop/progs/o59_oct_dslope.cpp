#include <bits/stdc++.h>
using namespace std;
const int X = 8e4 + 5, Y = 42, MD = 1e9 - 1;
int N, K, ar[X], st[X];
int ft[Y][X];
void ud(int a, int po, int va){for(; po <= N; po += -po & po) ft[a][po] = (ft[a][po] + va) % MD;}
int gt(int a, int po){if(!a) return 1; int re = 0; for(; po; po -= -po & po) re = (re + ft[a][po]) % MD; return re; }
int main(){
	scanf("%d %d", &N, &K);
	for(int i = 1, u; i <= N; i++) scanf("%d", &u), ar[i] = u;
	iota(st, st + N, 1); sort(st, st + N, [](int l, int r){return ar[l] > ar[r];});
	for(int i = 0; i < N; i++) for(int j = K; j; j--) ud(j, st[i], gt(j - 1, st[i]));
	printf("%d", gt(K, N));
}
