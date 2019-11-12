#include <bits/stdc++.h>
using namespace std;
const int X = 1e5 + 4;
int N, in[X], ar[X], ft[X], an;
void ud(int x) { for(x++ ; x <= N; x += -x & x) ft[x]--; }
int qu(int x) { int re = 0; for(x++ ; x; x -= -x & x) re += ft[x]; return re;}
int main(){
	scanf("%d", &N); fill_n(ft + 1, N, 1);
	for(int i = 1, k; i <= N; i++) ft[min(N + 1, i + (-i & i))] += ft[i];
	for(int i = 0, o; i < N; i++) scanf("%d", &o), in[o] = i;
	for(int i = 0, o; i < N; i++) scanf("%d", &o), ar[i] = in[o];
	for(int i = 0; i < N; i++) ud(ar[i]), an += (qu(ar[i]) != 0);
	printf("%d", an);
}
