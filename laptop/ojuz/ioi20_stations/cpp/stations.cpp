#include "stations.h"
#include <bits/stdc++.h>
using namespace std;
const int X = 1005;
vector<int> ed[X], lb;
bool lv[X];
int num;
void init(int N){
	lb.assign(N, 0);
	for(int i = 0; i < N; ++i) ed[i].clear();
	memset(lv, 0, sizeof lv);
	num = 0;
}
void dfs(int u, int p){
	lv[u] = !lv[p];
	if(lv[u]) lb[u] = num++;
	for(int v: ed[u]) if(v != p) dfs(v, u);
	if(!lv[u]) lb[u] = num++;
}
vector<int> label(int N, int K, vector<int> ar1, vector<int> ar2) {
	init(N);
	for(int i = 0; i < N - 1; ++i) ed[ar1[i]].emplace_back(ar2[i]), ed[ar2[i]].emplace_back(ar1[i]);
	dfs(0, 0);
	return lb;
}
int find_next_station(int s, int t, vector<int> c) {
	if(c.size() == 1) return c[0];
	sort(c.begin(), c.end());
	if(c[0] < s){
		if(t < c[1] or t > s) return c[0];
		return *(upper_bound(c.begin(), c.end(), t) - 1);
	} else {
		if(t > c[c.size() - 2] or t < s) return c.back();
		return *lower_bound(c.begin(), c.end(), t);
	}
}