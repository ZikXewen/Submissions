#include <bits/stdc++.h>
#define lint long long
using namespace std;
const int X = 1e5 + 5;
int N, h[X], r[X], st[X];
lint ft[X], an;
void ud(int u){for(++u; u <= N; u += -u & u) ++ft[u];}
lint qu(int u){lint re = 0; for(++u; u; u -= -u & u) re += ft[u]; return re;}
int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++) scanf("%d", h + i);
	for(int i = 0; i < N; i++) scanf("%d", r + i);
	iota(st, st + N, 0); sort(st, st + N, [](int l, int r){return h[l] > h[r];});
	for(int i = 0; i < N; i++){
		int u = st[i], rr = min(N - 1, u + r[u]), ll = max(-1, u - 1 - r[u]);
		ud(u);
		an += qu(u - 1) - qu(ll);
		an += (rr - u) - qu(rr) + qu(u);
	}
	printf("%lld", an);
}
/*
5
5 4 3 2 1
0 1 2 3 4
*/