#include <bits/stdc++.h>
#define ii tuple<int, int, int, int>
using namespace std;
const int X = 1 << 19;
int N, M, st[X], ll[X], rr[X], sm[X], v[X];
void bd(int l = 1, int r = N, int id = 1){
	if(l == r) {st[id] = ll[id] = rr[id] = sm[id] = v[l]; return;}
	int m = (l + r) >> 1;
	bd(l, m, id << 1); bd(m + 1, r, id << 1 | 1);
	st[id] = max(rr[id << 1] + ll[id << 1 | 1], max(st[id << 1], st[id << 1 | 1]));
	ll[id] = max(ll[id << 1], sm[id << 1] + ll[id << 1 | 1]);
	rr[id] = max(rr[id << 1 | 1], sm[id << 1 | 1] + rr[id << 1]);
	sm[id] = sm[id << 1] + sm[id << 1 | 1];
}
ii que(int al, int ar, int l = 1, int r = N, int id = 1){
	if(al <= l && ar >= r) return {st[id], ll[id], rr[id], sm[id]};
	int m = (l + r) >> 1; 
	if(ar <= m) return que(al, ar, l, m, id << 1);
	if(al > m) return que(al, ar, m + 1, r, id << 1 | 1);
	ii ln = que(al, ar, l, m, id << 1), lr = que(al, ar, m + 1, r, id << 1 | 1);
	return {
		max(get<2>(ln) + get<1>(lr), max(get<0>(ln), get<0>(lr))),
		max(get<1>(ln), get<3>(ln) + get<1>(lr)),
		max(get<2>(lr), get<3>(lr) + get<2>(ln)),
		get<3>(lr) + get<3>(ln)
	};
}
int main(){
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; i++) scanf("%d", &v[i]);
	bd();
	for(int u, v; M; M--){
		scanf("%d %d", &u, &v);
		printf("%d\n", max(get<0>(que(u+1, v+1)), 0));
	}
}
/*
4 5
1 -2 3 -4
0 3
0 0
1 1
2 2
0 3
*/
