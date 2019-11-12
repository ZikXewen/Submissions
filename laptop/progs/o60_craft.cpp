#include <bits/stdc++.h>
#define LL long long
using namespace std;
int N, M, A[25];
LL rec(int lv, LL x) {
	LL cur = (x << 1 | 1) - A[lv];
	if(cur < 2) return 0LL;
	if(lv == 1) return cur;
	if(!(cur & 1)) return rec(lv - 1, cur >> 1) << 1;
	LL a = rec(lv - 1, cur >> 1), b = rec(lv - 1, (cur >> 1) + 1);
	if(a && b) return  a+b;
	else return 0LL;
}
int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i < N; ++i) scanf("%d", &A[i]);
	LL an = rec(N - 1, M);
	if(an) printf("%lld", an);
	else printf("-1");
}
