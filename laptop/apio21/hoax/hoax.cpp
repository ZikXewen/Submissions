#include "hoax.h"
#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> ii;
vector<int> p;
int fd(int x){return p[x] < 0? x : (p[x] = fd(p[x]));}
void un(int u, int v){if((u = fd(u)) != (v = fd(v))) p[v] += p[u], p[u] = v;}
void init(int N, int S, vector<int> T, vector<vector<int>> A, vector<vector<int>> B) {
	int ct = 0;
	vector<int> po;
	vector<ii> q;
	p.assign(N, -1);
	for(int i = 0; i < N; ++i) for(int j = 0; j < T[i]; ++j)
		q.emplace_back(A[i][j], B[i][j], i);
	sort(q.begin(), q.end());
	for(auto [u, v, w]: q){
		static int ls = v, hd = w;
		if(u <= ls) ls = max(ls, v), un(w, hd);
		else ls = v, hd = w;
	}
}
int count_users(int u) {return -p[fd(u)];}
/*
5 10 2
2 2 4 7 9
1 1 3
1 1 1
1 9 10
1 5 6
*/