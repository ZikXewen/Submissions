#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;
const int X = 3e5 + 5;
struct one{
	int ct = 0;
	vector<int> ar;
	stack<ii> stk;
	one() {}
	one(int sz, int va) : ar(vector<int>(sz, va)) {ct = sz;}
	int sz() { return stk.size(); }
	int cur() { return ct;}
	void put(int po, int va){ stk.emplace(po, ar[po]); ar[po] = va; }
	void rb(int sz, int oct){ while(stk.size() > sz) {auto [u, v] = stk.top(); stk.pop(); ar[u] = v;} ct = oct;}
	int fd(int x){ return (ar[x] < 0)? x : fd(ar[x]); }
	void un(ii k){
		int u = fd(k.first), v = fd(k.second);
		if(u == v) return;
		if(ar[u] > ar[v]) swap(u, v);
		--ct; put(u, ar[u] + ar[v]); put(v, u);
	}
} dsu;
int N, M;
map<ii, int> mp;
vector<pair<int, ii>> rgt[X], lft[X];
vector<int> ask; int ans[X];
void sol(int l, int r){
	if(l == r) return void(ans[l] = dsu.cur());
	int m = l + r >> 1, old = dsu.sz(), oct = dsu.cur();
	for(int i = m + 1; i <= r; ++i) for(auto [u, v]: rgt[i]) if(u <= l) dsu.un(v);
	sol(l, m); dsu.rb(old, oct);
	for(int i = l; i <= m + 1; ++i) for(auto [u, v]: lft[i]) if(u > r) dsu.un(v);
	sol(m + 1, r); dsu.rb(old, oct);
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("connect.in", "r", stdin); freopen("connect.out", "w", stdout);
	cin >> N >> M; dsu = one(N, -1);
	for(int u, v, i = 0; i < M; ++i){
		string typ; cin >> typ;
		if(typ[0] == '?'){ ask.emplace_back(i); continue; }
		cin >> u >> v; if(--u > --v) swap(u,  v); ii p(u, v);
		if(typ[0] == '+') mp[p] = i;
		else rgt[i].emplace_back(mp[p], p), lft[mp[p]].emplace_back(i, p), mp.erase(p);
	}
	for(auto [u, v]: mp) rgt[M].emplace_back(v, u), lft[v].emplace_back(M, u);
	sol(0, M);
	for(int i: ask) cout << ans[i] << '\n';
}
