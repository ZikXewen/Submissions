#include <bits/stdc++.h>
#define ii pair<int, int>
#define iii tuple<int, int, int>
using namespace std;
const int X = 6e5 + 5;
int N, M, ct, p[X], pr[X];
bool ans[X];
map<ii, int> mp;
vector<ii> ve[X << 2]; // unsure size
stack<ii> sp, spr;
void add(ii va, int bg, int ed, int l = 1, int r = M, int id = 1){
	if(l > ed or r < bg) return;
	if(l >= bg and r <= ed) return ve[id].emplace_back(va), void();
	int m = (l + r) >> 1;
	add(va, bg, ed, l, m, id << 1);
	add(va, bg, ed, m + 1, r, id << 1 | 1);
}
ii fd(int x){
	if(p[x] < 0) return ii(x, pr[x]);
	auto [u, v] = fd(p[x]);
	return ii(u, v ^ pr[x]);
}
bool un(int u, int v){
	auto [pu, vu] = fd(u); auto [pv, vv] = fd(v);
	if(pu == pv) return vu != vv;
	if(p[pu] > p[pv]) swap(pu, pv), swap(vu, vv);
	sp.emplace(pu, p[pu]); p[pu] += p[pv];
	sp.emplace(pv, p[pv]); p[pv] = pu;
	spr.emplace(pv, pr[pv]); pr[pv] = vu ^ vv ^ 1;
	return 1;
}
void sol(int l = 1, int r = M, int id = 1, bool yes = 1){
	int rbp = sp.size(), rbpr = spr.size(), m = (l + r) >> 1;
	for(auto [u, v]: ve[id]) yes &= un(u, v);
	if(!yes or l == r) ans[l] = yes;
	else sol(l, m, id << 1), sol(m + 1, r, id << 1 | 1);
	while(sp.size() > rbp){ auto [u, v] = sp.top(); sp.pop(); p[u] = v; }
	while(spr.size() > rbpr){ auto [u, v] = spr.top(); spr.pop(); pr[u] = v; }
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;
	for(int i = 0, u, v, w; i < M; ++i){
		cin >> u >> v >> w;
		if(v > w) swap(v, w);
		if(u) mp[ii(v, w)] = i + 1;
		else 
			add(ii(v, w), mp[ii(v, w)], i), 
			mp.erase(ii(v, w)); 
	}
	for(auto [u, v]: mp) add(u, v, M);
	memset(p, -1, sizeof p);
	sol();
	for(int i = 1; i <= M; ++i) cout << (ans[i]? "yes\n" : "no\n");
}