#include "fun.h"
#include <bits/stdc++.h>
#define _s(x) (grp[x].size())
#define _b(x) (grp[x].back())
#define i2 ((i + 1) % 3)
#define i3 ((i + 2) % 3)
using namespace std;
typedef pair<int, int> ii;
vector<int> createFunTour(int N, int Q) {
	int cen = 0;
	for(int i = 1, mnsz = N; i < N; ++i) {
		int tem = attractionsBehind(0, i); // N - 1
		if((tem << 1) >= N and tem < mnsz) cen = i, mnsz = tem;
	}
	vector<int> adj, dis(N), ans;
	for(int i = 0; i < N; ++i) if(i != cen and (dis[i] = hoursRequired(cen, i)) == 1) adj.emplace_back(i); // N - 1
	vector<int> grp[3];
	for(int i = 0; i < N; ++i) if(i != cen) {
		if(hoursRequired(adj[0], i) == dis[i] - 1) grp[0].emplace_back(i); // N
		else if(hoursRequired(adj[1], i) == dis[i] - 1) grp[1].emplace_back(i); // N
		else grp[2].emplace_back(i);
	}
	for(auto &i: grp) sort(i.begin(), i.end(), [&](int u, int v){return dis[u] < dis[v];});
	// cout << _s(0) << ' ' << _s(1) << ' ' << _s(2);
	--N;
	auto push = [&](int u){ans.emplace_back(_b(u)); grp[u].pop_back(); --N;};
	for(int ls = -1, mx = 0; _s(0) and _s(1) and _s(2);){
		for(int i = 0; i < 3; ++i) if(_s(i) << 1 >= N) {
			if(i2 == ls){
				if(dis[_b(i3)] > mx) push(i3);
				else push(i);
			} else if(i3 == ls){
				if(dis[_b(i2)] > mx) push(i2);
				else push(i);
			}
			for(auto j: grp[i3]) grp[i2].emplace_back(j);
			vector<int>().swap(grp[i3]);
			sort(grp[i2].begin(), grp[i2].end(), [&](int u, int v){return dis[u] < dis[v];});
			ls = -2;
			break;
		} if(ls == -2) break;
		mx = 0;
		for(int i = 0; i < 3; ++i) if(i != ls) mx = max(mx, dis[_b(i)]);
		for(int i = 0; i < 3; ++i) if(i != ls and mx == dis[_b(i)]) 
			{push(ls = i); break;}
	}
	if(!_s(0)) grp[0].swap(grp[2]);
	if(!_s(1)) grp[1].swap(grp[2]);
	if(_s(0) < _s(1)) grp[0].swap(grp[1]);
	for(int i = 0, _N = N; i < _N; ++i) push(i & 1);
	ans.emplace_back(cen);
	// for(int i: ans) cout << i << ' ';
	return ans;
}
/*
7 400000
0 1
0 5
0 6
1 2
1 4
2 3
*/