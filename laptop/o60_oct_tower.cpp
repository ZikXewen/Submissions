#include <bits/stdc++.h>
using namespace std;
const int MXN = 6e5; 
int N, M, st[MXN], no[MXN], ll[MXN], rr[MXN], lz[MXN];
void ud(int l, int r, int id, int al, int ar, int av){
	if(lz[id]){
		st[id] += lz[id];
		ll[id] += lz[id];
		rr[id] += lz[id];
		if(l != r) lz[id << 1] += lz[id], lz[id << 1 | 1] += lz[id];
		lz[id] = 0;
	}
	if(l > ar || r < al) return;
	if(l >= al && r <= ar){
		st[id] += av;
		ll[id] += av;
		rr[id] += av;
		if(l != r) lz[id << 1] += av, lz[id << 1 | 1] += av;
		return;
	}
	int m = (l + r) >> 1;
	ud(l, m, id << 1, al, ar, av);
	ud(m + 1, r, id << 1 | 1, al, ar, av);
	ll[id] = ll[id << 1], rr[id] = rr[id << 1 | 1];
	if(st[id << 1] < st[id << 1 | 1]) { st[id] = st[id << 1 | 1], no[id] = no[id << 1 | 1]; return; }
	if(st[id << 1] > st[id << 1 | 1]) { st[id] = st[id << 1], no[id] = no[id << 1]; return; }
	st[id] = st[id << 1];
	no[id] = no[id << 1] + no[id << 1 | 1];
	if(rr[id << 1] == ll[id << 1 | 1] && ll[id << 1 | 1] == st[id]) no[id]--;
}
int main(){
	scanf("%d %d", &N, &M);
	for(int i = 0; i < MXN; i++) no[i] = 1;
	for(int i = 0, u, v, w; i < M; i++){
		scanf("%d %d %d", &u, &v, &w);
		ud(1, N, 1, u, v, w);
		cout << st[1] << ' ' << no[1] << '\n';
	}
}
