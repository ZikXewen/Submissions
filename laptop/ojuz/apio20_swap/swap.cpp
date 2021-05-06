#include "swap.h"
#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> ii;
const int X = 1e5 + 5, R = 1e9 + 5, L = 20;
int N, M, CT;
vector<ii> ed;
struct node{
	int nl, e1, e2, id, dp;
	node *pa[L], *ppa;
	node* fd(){return ppa? ppa = ppa -> fd() : this;}
	void ste(int u, int v){e1 = u, e2 = v;}
	void stp(node *u){pa[0] = ppa = u;}
	node(int u) : id(u), nl(), e1(u), e2(u), pa(), ppa(), dp() {}
} *tr[X << 1];
void un(int u, int v, int po){
	node *pu = tr[u] -> fd(), *pv = tr[v] -> fd();
	if(pu == pv){
		if(!pu -> nl) pu -> nl = po;
		return;
	}
	node *nw = tr[CT++] = new node(CT);
	pu -> stp(nw), pv -> stp(nw);
	if(pv -> nl or pu -> nl) return nw -> nl = po, void();
	if(u == pu -> e1 and v == pv -> e1) return nw -> ste(pu -> e2, pv -> e2), void();
	if(u == pu -> e1 and v == pv -> e2) return nw -> ste(pu -> e2, pv -> e1), void();
	if(u == pu -> e2 and v == pv -> e1) return nw -> ste(pu -> e1, pv -> e2), void();
	if(u == pu -> e2 and v == pv -> e2) return nw -> ste(pu -> e1, pv -> e1), void();
	nw -> nl = po;
}
void init(int _N, int _M, vector<int> U, vector<int> V, vector<int> W) {
	N = _N; M = _M;
	for(int i = 0; i < N; ++i) tr[CT++] = new node(i);
	for(int i = 0; i < M; ++i) ed.emplace_back(U[i], V[i], W[i]);
	sort(ed.begin(), ed.end(), [=](ii u, ii v){return get<2>(u) < get<2>(v);});
	for(auto [u, v, w]: ed) un(u, v, w);
	tr[CT - 1] -> dp = 1;
	for(int i = 1; i < L; ++i) for(int j = 0; j < CT; ++j) if(tr[j] -> pa[i - 1]) {
		tr[j] -> pa[i] = tr[j] -> pa[i - 1] -> pa[i - 1];
		if(tr[j] -> pa[i - 1] -> dp) tr[j] -> dp = tr[j] -> pa[i - 1] -> dp + (1 << (i - 1));
	}
}
int getMinimumFuelCapacity(int u, int v) {
	node *pu = tr[u], *pv = tr[v];
	if(pu -> dp < pv -> dp) swap(pu, pv);
	for(int i = L - 1; i >= 0; --i) if(pu -> pa[i] and pu -> pa[i] -> dp >= pv -> dp) pu = pu -> pa[i];
	if(pu != pv){
		for(int i = L - 1; i >= 0; --i) if(pu -> pa[i] != pv -> pa[i]) pu = pu -> pa[i], pv = pv -> pa[i];
		pu = pu -> pa[0];
	}
	if(pu -> nl) return pu -> nl;
	for(int i = L - 1; i >= 0; --i) if(pu -> pa[i] and !pu -> pa[i] -> nl) pu = pu -> pa[i];
	return pu -> pa[0]? pu -> pa[0] -> nl : -1;
}
/*
5 6
0 1 4
0 2 4
1 2 1
1 3 2
1 4 10
2 3 3
3
1 2
2 4
0 1

3 2
0 1 5
0 2 5
1
1 2
*/