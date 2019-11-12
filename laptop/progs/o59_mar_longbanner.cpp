#include <bits/stdc++.h>
using namespace std;
const int X = 1e5 + 5;
int N, H, L, ft[X], po[X], he[X], cpr[X], sz, an;
void ud(int u, int va) { for(; u <= sz; u += -u & u) ft[u]+= va; }
int qu(int u) { int re = 0; for(; u; u -= -u & u) re += ft[u]; return re;}
int lb(int u) { return lower_bound(cpr, cpr + sz, u) - cpr + 1; }
int ub(int u) { return upper_bound(cpr, cpr + sz, u) - cpr + 1; }
int main() {
	scanf("%d %d %d", &N, &H, &L);
	for(int i = 0; i < N; i++) scanf("%d %d", &po[i], &he[i]);
	copy(he, he + N, cpr); sort(cpr, cpr + N);
	sz = unique(cpr, cpr + N) - cpr;
	for(int i = 0, ls = 0; i < N; i++) { 
		ud(lb(he[i]), 1);
		while(po[i] - po[ls] > H) ud(lb(he[ls++]), -1);
		for(int j = 0; j <= L; j++) an = max(an, qu(ub(he[i] + j) - 1) - qu(lb(he[i] - L + j) - 1));
	}
	printf("%d", an);
}
/*
5 10 2
10 10
12 20
13 10
19 20
20 14
*/
