#include <bits/stdc++.h>
#define ii pair<int, int>
#define iii pair<int, ii>
using namespace std;
const int X = 6e5 + 5;
bool ans[X];
int N, M, p[X], par[X];
map<ii, int> mp;
vector<iii> rgt[X], lft[X];
stack<ii> sp, spar;
ii fd(int x){
	if(p[x] < 0) return ii(x, par[x]);
	auto [u, v] = fd(p[x]);
	return ii(u, v ^ par[x]);
}
bool un(ii u){
	auto [uu, uv] = fd(u.first); auto [vu, vv] = fd(u.second);
	if(uu == vu) return uv != vv;
	if(p[uu] > p[vu]) swap(uu, vu), swap(uv, vv); // v must be smaller than u
	sp.emplace(uu, p[uu]); p[uu] += p[vu];
	sp.emplace(vu, p[vu]); p[vu] = uu;
	spar.emplace(vu, par[vu]); par[vu] = uv ^ vv ^ 1;
	return 1;
}
void rb(int rbp, int rbpar){
	while(sp.size() > rbp){ auto [u, v] = sp.top(); sp.pop(); p[u] = v; }
	while(spar.size() > rbpar){ auto [u, v] = spar.top(); spar.pop(); par[u] = v; }
}
void sol(int l, int r, bool ret){
	if(l == r || !ret) return void(ans[l] = ret);
	int m = l + r >> 1, rbp = sp.size(), rbpar = spar.size();
	bool rel = 1, rer = 1;
	for(int i = m + 1; i <= r; ++i) for(auto [u, v]: rgt[i]) if(u <= l) rel &= un(v);
	sol(l, m, rel); rb(rbp, rbpar);
	for(int i = l; i <= m + 1; ++i) for(auto [u, v]: lft[i]) if(u > r) rer &= un(v);
	sol(m + 1, r, rer); rb(rbp, rbpar);
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M; memset(p, -1, sizeof p);
	for(int i = 0, u, v, w; i < M; ++i){
		cin >> w >> u >> v;
		if(u > v) swap(u, v); ii p(u, v);
		if(w) mp[p] = i;
		else rgt[i].emplace_back(mp[p], p), lft[mp[p]].emplace_back(i, p), mp.erase(p);
	}
	for(auto [p, v]: mp) rgt[M].emplace_back(mp[p], p), lft[mp[p]].emplace_back(M, p);
	sol(0, M, 1);
	for(int i = 0; i < M; ++i) cout << (ans[i]? "yes\n" : "no\n");
}
//case 13
