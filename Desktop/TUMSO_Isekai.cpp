#include <bits/stdc++.h>
using namespace std;
const int X = 2e5 + 5;
int N, M, P, Q, sm, nt, ct;
int le[X], dmg[X], h[X], hp[X], st[X], stt[X], ans[X], hd[X];
bool stat[X];
long long an;
int fd(int u){ return (hd[u] >= 0)? hd[u] = fd(hd[u]) : u; }
void mrg(int u, int v){ 
	u = fd(u), v = fd(v);
	sm += dmg[- hd[u] - hd[v]] - dmg[- hd[u]] - dmg[- hd[v]];
	hd[u] += hd[v], hd[v] = u;
}
void add(int u){
	stat[u] = 1;
	if(u && stat[u - 1]) mrg(u - 1, u);
	if(u < N && stat[u + 1]) mrg(u, u + 1);
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M >> P >> Q;
	for(int i = 0; i < N; ++i) cin >> le[i];
	for(int i = 2; i <= M + 1; ++i) cin >> dmg[i];
	for(int i = 0; i < P; ++i) cin >> h[i];
	for(int i = 0; i < Q; ++i) cin >> hp[i];
	iota(st, st + N, 0); iota(stt, stt + Q, 0); memset(hd, -1, sizeof hd);
	sort(st, st + N, [](const int &l, const int &r){return le[l] > le[r];});
	sort(stt, stt + Q, [](const int &l, const int &r){return hp[l] < hp[r];});
	for(int cr = 0; cr < N; ++cr)
		if(le[st[cr]] >= h[nt]) {if(!stat[st[cr]]) add(st[cr]);}
		else {an += sm, --cr, ++nt; while(hp[stt[ct]] <= an && ct < Q) ans[stt[ct++]] = nt;}
	while(nt < P) {an += sm, ++nt; while(hp[stt[ct]] <= an && ct < Q) ans[stt[ct++]] = nt;}
	for(int i = 0; i < Q; ++i) cout << (ans[i]? ans[i] : -1) << ' ';
}
/*
11 3 5 4
5 2 3 1 7 1 3 4 4 6 2
1 2 3
4 6 4 3 2
5 7 11 12
*/