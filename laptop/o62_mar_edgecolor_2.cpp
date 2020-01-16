#include <bits/stdc++.h>
#define ii pair<int, int>
#define iii pair<int, ii>
using namespace std;
const int X = 6e5 + 5;
bool ans[X]; int N, M;
map<ii, int> mp;
vector<iii> rgt[X], lft[X];
struct one{
	int ar[X];
	stack<ii> stk;
	int at(int u){ return ar[u]; }
	void put(int po, int va){ stk.emplace(po, ar[po]); ar[po] = va; }
	void rb(int sz){ while(stk.size() > sz){ auto [u, v] = stk.top(); stk.pop(); ar[u] = v; } }
	int ssz(){ return stk.size(); }
} dsu, par;
ii fd(int x){
	if(dsu.at(x) < 0) return ii(x, par.at(x));
	auto [u, v] = fd(dsu.at(x));
	return ii(u, v ^ par.at(x));
}
bool un(ii u){
	auto [uu, uv] = fd(u.first); auto [vu, vv] = fd(u.second);
	if(uu == vu) return uv != vv;
	if(dsu.at(uu) > dsu.at(vu)) swap(uu, vu), swap(uv, vv); // v must be smaller than u
	dsu.put(uu, dsu.at(uu) + dsu.at(vu));
	dsu.put(vu, uu); par.put(vu, uv ^ vv ^ 1);
	return 1;
}
void sol(int l, int r, bool ret){
	if(l == r || !ret) return void(ans[l] = ret);
	int m = l + r >> 1, rbp = dsu.ssz(), rbpar = par.ssz();
	bool rel = 1, rer = 1;
	for(int i = m + 1; i <= r; ++i) for(auto [u, v]: rgt[i]) if(u <= l) rel &= un(v);
	sol(l, m, rel); dsu.rb(rbp), par.rb(rbpar);
	for(int i = l; i <= m + 1; ++i) for(auto [u, v]: lft[i]) if(u > r) rer &= un(v);
	sol(m + 1, r, rer); dsu.rb(rbp), par.rb(rbpar);
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M; memset(dsu.ar, -1, sizeof dsu.ar);
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
