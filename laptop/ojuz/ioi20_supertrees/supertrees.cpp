#include "supertrees.h"
#include <bits/stdc++.h>
using namespace std;
const int X = 1005;
int p[X], ls[X];
int fd(int u){return p[u] = ((p[u] == u)? u : fd(p[u]));}
vector<vector<int>> an;
void un(int u, int v){
	u = fd(u), v = fd(v);
	if(u == v) return;
	an[u][ls[v]] = an[ls[v]][u] = 1; p[u] = v; ls[v] = ls[u];
}
int construct(vector<vector<int>> ar) {
	int N = ar.size();
	an.assign(N, vector<int>(N, 0));
	iota(p, p + N, 0), iota(ls, ls + N, 0);
	for(int i = 0; i < N; ++i) for(int j = i + 1; j < N; ++j){
		if(ar[i][j] == 3 or ar[i][j] != ar[j][i]) return 0;
		if(ar[i][j] == 1) un(i, j);
	}
	for(int i = 0; i < N; ++i) for(int j = i + 1; j < N; ++j) if(ar[i][j] != 1 and fd(i) == fd(j)) return 0;
	iota(ls, ls + N, 0);
	for(int i = 0; i < N; ++i) for(int j = i + 1; j < N; ++j) if(ar[i][j] == 2) un(i, j);
	for(int i = 0; i < N; ++i) if(p[i] == i and ls[i] != i){
		if(an[ls[i]][i] == 1) return 0;
		an[ls[i]][i] = an[i][ls[i]] = 1;
	}
	for(int i = 0; i < N; ++i) for(int j = i + 1; j < N; ++j) if(ar[i][j] == 0 and fd(i) == fd(j)) return 0;
	build(an);
	return 1;
}
