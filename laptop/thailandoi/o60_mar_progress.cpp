#include <bits/stdc++.h>
using namespace std;
const int X = 1e5 + 5;

int N, M, ar[X], mx[X << 2], ll[X << 2], rr[X << 2], sm[X << 2];
void bd(int l = 1, int r = N, int id = 1){
	if(l == r) {mx[id] = ll[id] = rr[id] = sm[id] = ar[l]; return;}
	int m = (l + r) >> 1;
	bd(l, m, id << 1); bd(m + 1, r, id << 1 | 1);
	mx[id] = max(max(mx[id << 1], mx[id << 1 | 1]), rr[id << 1] + ll[id << 1 | 1]);
	ll[id] = max(ll[id << 1], ll[id << 1 | 1] + sm[id << 1]);
	rr[id] = max(rr[id << 1 | 1], rr[id << 1] + sm[id << 1 | 1]);
	sm[id] = sm[id << 1] + sm[id << 1 | 1];
}
void ud(int po, int va, int l = 1, int r = N, int id = 1) {
	if(l == r) {mx[id] = ll[id] = rr[id] = sm[id] = va; return;}
	int m = (l + r) >> 1;
	if(po <= m) ud(po, va, l, m, id << 1);
	else ud(po, va, m + 1, r, id << 1 | 1);
	mx[id] = max(max(mx[id << 1], mx[id << 1 | 1]), rr[id << 1] + ll[id << 1 | 1]);
	ll[id] = max(ll[id << 1], ll[id << 1 | 1] + sm[id << 1]);
	rr[id] = max(rr[id << 1 | 1], rr[id << 1] + sm[id << 1 | 1]);
	sm[id] = sm[id << 1] + sm[id << 1 | 1];
}
int main(){
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; i++) scanf("%d", ar + i);
	bd(); printf("%d\n", mx[1]);
	for(int i = 0, u, v; i < M; i++) scanf("%d %d", &u, &v), ud(u + 1, v), printf("%d\n", mx[1]);
}
