#include <bits/stdc++.h>
using namespace std;
const int X = 2e5 + 5, LX = 20;
int N, Q, L, S, A, B, l[X], r[X], pa[X][LX + 1], nx[2][X], ds[2][X];
bool mk[X], ed[X];
void dfs(int u, int pr, int di, bool typ){
	for(int i = 1; i <= LX; ++i) pa[u][i] = pa[pa[u][i - 1]][i - 1];
	if(mk[u]) 
		nx[typ][pr] = u, ds[typ][pr] = di, 
		pa[l[u]][0] = pa[r[u]][0] = u,
		dfs(l[u], u, 1, 0), dfs(r[u], u, 1, 1);
	else if(ed[u]) nx[typ][pr] = u, ds[typ][pr] = di;
	else pa[l[u]][0] = u, dfs(l[u], pr, di + 1, typ);
}
int dir(){
	int res = ((S & 8) >> 3);
	S = (S * A + B) % 40507;
	return res;
}
int qu(int le, int u){
	if(le <= 0) {for(int i = LX; i >= 0; --i) if((1 << i) + le <= 0) le += (1 << i), u = pa[u][i]; return u;}
	if(ed[u]) return u;
	int di = dir(); return qu(le - ds[di][u], nx[di][u]);
}
int main(){
	scanf("%d %d", &N, &Q);
	for(int i = 0, ct, u, v; i < N; i++){
		scanf("%d %d", &u, &v); 
		ct = (int)(u != -1) + (int) (v != -1);
		if(ct == 2) mk[i] = 1, l[i] = u, r[i] = v;
		else if(ct == 1) l[i] = (u != -1)? u : v;
		else ed[i] = 1;
	}
	dfs(0, 0, 0, 0);
	while(Q--){
		scanf("%d %d %d %d", &L, &S, &A, &B);
		printf("%d\n", mk[0] ? qu(L, 0) : qu(L - ds[0][0], nx[0][0]));
	}
}
